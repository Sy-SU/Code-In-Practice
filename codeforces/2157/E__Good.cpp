#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

template<class Info, class Tag>
struct SegmentTree {
    /*
    线段树维护区间加，查询区间和，区间最值
    使用 SegmentTree<Info, Tag> st(a); 初始化线段树
    区间加: st.modify(L, R, val);
    查询区间和: st.query(L, R).sum;
    查询区间最大值: st.query(L, R).max;
    查询区间最小值: st.query(L, R).min;
    */
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    explicit SegmentTree(const std::vector<i64>& a) {
        n = (int)a.size() - 1;
        info.assign(4 * n + 10, Info()), tag.assign(4 * n + 10, Tag());
        if (n) {
            build(1, 1, n, a);
        }
    }

    void modify(int L, int R, i64 val) {
        if (L > R || n == 0) {
            return;
        }
        modify(1, 1, n, L, R, Tag(val));
    }

    Info query(int L, int R) {
        if (L > R) {
            return Info();
        }
        return query(1, 1, n, L, R);
    }

private:
    void pushup(int u) {
        info[u] = info[u << 1] + info[u << 1 | 1];
    }

    void apply(int u, const Tag &t) {
        info[u].apply(t), tag[u].apply(t);
    }

    void pushdown(int u) {
        apply(u << 1, tag[u]), apply(u << 1 | 1, tag[u]);
        tag[u] = Tag();
    }

    void build(int u, int l, int r, const std::vector<i64>& a) {
        
        if (l == r) {
            info[u] = Info(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        pushup(u);
    }

    void modify(int u, int l, int r, int L, int R, const Tag &t) {
        if (L <= l && r <= R) {
            apply(u, t);
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        if (L <= mid) {
            modify(u << 1, l, mid, L, R, t);
        }
        if (R > mid) {
            modify(u << 1 | 1, mid + 1, r, L, R, t);
        }
        pushup(u);
    }

    Info query(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return info[u];
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        Info res = Info();
        if (L <= mid) {
            res = res + query(u << 1, l, mid, L, R);
        }
        if (R > mid) {
            res = res + query(u << 1 | 1, mid + 1, r, L, R);
        }
        return res;
    }
};

struct Tag {
    // Lazy tag，例如区间加法，区间乘法
    i64 add; // 区间加法

    Tag() : add(0) {}
    Tag(i64 x) : add(x) {}

    void apply(const Tag &oth) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        add += oth.add;
    }
};

struct Info {
    // 需要维护的信息，例如区间和，区间最值
    i64 max;
    int cnt; // 区间长度

    Info() : max(-INF), cnt(0) {}
    Info(i64 x) : max(x), cnt(1) {}
    Info(i64 max, int cnt) : max(max), cnt(cnt) {}

    Info operator+(const Info &oth) const {
        return {std::max(max, oth.max), cnt + oth.cnt};
    }

    void apply(const Tag &tag) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        max += tag.add;
    }
};

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int len = 3 * n + 2;

	std::vector<i64> cnt(len + 1);
	for (int i = 1; i <= n; i++) {
		cnt[n + a[i]]++;
	}

	SegmentTree<Info, Tag> sg(cnt);

	i64 maxcnt = sg.query(1, len).max;
	// for (int i = 1; i <= 4 * n; i++) {
	// 	maxcnt = std::max(maxcnt, cnt[i]);
	// }

	if (maxcnt <= k) {
		std::cout << 0 << '\n';
		return;
	}

	// std::cerr << "ok" << '\n';

	std::vector<std::pair<int, int>> seg;
	int lst = -1;
	for (int i = 1; i <= len; i++) {
		if (sg.query(i, i).max) {
			//
		} else {
			// lst ~ i - 1
			if (lst != -1 && i - 1 >= lst) {
				seg.push_back({lst, i - 1});
			}
			lst = i + 1;
		}
	}
	for (int r = 1; r <= n; r++) {
		// std::cerr << r << '\n';
		std::vector<std::pair<int, int>> ts;
		for (auto [l, r] : seg) {
			cnt[r]--, cnt[l - 1]++;
			sg.modify(r, r, -1), sg.modify(l - 1, l - 1, 1);
			if (sg.query(r, r).max == 0) {
				r--;
			}
			// std::cerr << l << " " << r << '\n';
			if (!ts.empty() && ts.back().second == l - 1) {
				auto [ll, rr] = ts.back();
				ts.pop_back();
				ts.push_back({ll, r});
			} else {
				ts.push_back({l - 1, r});
			}
		}
		seg = ts;

		maxcnt = sg.query(1, len).max;
		if (maxcnt <= k) {
			std::cout << r << '\n';
			return;
		}
 	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}