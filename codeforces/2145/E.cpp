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
    i64 min;

    Info() : min(INF) {}
    Info(i64 x) : min(x) {}
    Info operator+(const Info &oth) const {
        return {std::min(min, oth.min)};
    }

    void apply(const Tag &tag) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        min += tag.add;
    }
};

void solve() {
	i64 ac, dr;
	std::cin >> ac >> dr;

	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	std::vector<i64> val(n + 1);
	for (int i = 1; i <= n; i++) {
		val[i] = std::max(a[i] - ac, 0ll) + std::max(d[i] - dr, 0ll);
	}

	std::vector<int> cntv(n + 2);
	for (int i = 1; i <= n; i++) {
		if (val[i] <= n) {
			cntv[val[i]]++;
		}
	}

	int p = 0;
	for (int i = 0; i <= n; i++) {
		// val = i
		if (i <= p) {
			p += cntv[i];
		} else {
			break;
		}
	}

	std::vector<int> precnt(n + 1);
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			precnt[i] = cntv[i];
		} else {
			precnt[i] = precnt[i - 1] + cntv[i];
		}
	}

	// 最大的 i，使得 min(precnt[0] - 1, ... precnt[i - 1] - i) >= 0
	std::vector<i64> help(n + 2);
	for (int i = 1; i <= n + 1; i++) {
		help[i] = precnt[i - 1] - i;
	}

	// 维护 help
	SegmentTree<Info, Tag> st(help);

	int m;
	std::cin >> m;

	while (m--) {
		int ind;
		i64 newa, newd;
		std::cin >> ind >> newa >> newd;

		int lstv = val[ind];

		if (val[ind] <= n) {
			cntv[val[ind]]--;
			// help: val[ind] + 1 ~ n + 1 --
			// std::cerr << "-- : " << val[ind] << " " << n << '\n';
			st.modify(val[ind] + 1, n + 1, -1);
		}

		a[ind] = newa, d[ind] = newd;
		val[ind] = std::max(a[ind] - ac, 0ll) + std::max(d[ind] - dr, 0ll);

		int nowv = val[ind];

		if (val[ind] <= n) {
			cntv[val[ind]]++;
			// help: val[ind] + 1 ~ n + 1 ++
			// std::cerr << "++ : " << val[ind] << " " << n << '\n';
			st.modify(val[ind] + 1, n + 1, 1);
		}

		int lo = 1, hi = n + 1, ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (st.query(1, mid).min >= 0) {
				lo = mid + 1;
				ans = mid;
			} else {
				hi = mid - 1;
			}
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}