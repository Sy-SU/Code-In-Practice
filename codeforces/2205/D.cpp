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
        if (L > R || L < 1 || R > n) {
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
    i64 min, max, sum;
    int cnt; // 区间长度

    Info() : min(INF), max(0), sum(0), cnt(0) {}
    Info(i64 x) : min(x), max(x), sum(x), cnt(1) {}
    Info(i64 min, i64 max, i64 sum, int cnt) : min(min), max(max), sum(sum), cnt(cnt) {}

    Info operator+(const Info &oth) const {
        return {std::min(min, oth.min), std::max(max, oth.max), sum + oth.sum, cnt + oth.cnt};
    }

    void apply(const Tag &tag) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        min += tag.add, max += tag.add, sum += cnt * 1ll * tag.add;
    }
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// std::reverse(a.begin() + 1, a.end() - 1);

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	int indn = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == n) {
			indn = i;
			break;
		}
	}

	int maxn = n;

	auto f = [&](std::vector<i64> arr) -> i64 {
		int n = (int)arr.size() - 1;
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << arr[i] << " \n"[i == n];
		// }

		i64 res = 1e18;

		std::vector<i64> dppre(n + 2), dpsuf(n + 2);
		std::vector<i64> d(maxn + 2);
		SegmentTree<Info, Tag> vp(d), vs(d);
		// SegmentTree<Info, Tag> tr(arr);
		std::vector<int> stkp, stks;
		for (int i = 1; i <= n - 1; i++) {
			int up = stkp.empty() ? 0 : arr[stkp.front()];

			dppre[i] = vp.query(arr[i] + 1, up).max + 1;
			vp.modify(arr[i], arr[i], dppre[i]);
			// std::cerr << "p " << i << " = " << dppre[i] << '\n';
			// std::cerr << "can " << a[i] + 1 << " " << up << '\n';

			while (!stkp.empty() && arr[stkp.back()] < arr[i]) {
				int ind = stkp.back();
				vp.modify(arr[ind], arr[ind], -dppre[ind]);
				stkp.pop_back();
			}
			stkp.push_back(i);
		}

		for (int i = n - 1; i >= 1; i--) {
			int up = stks.empty() ? 0 : arr[stks.front()];
			
			dpsuf[i] = vs.query(arr[i] + 1, up).max + 1;
			vs.modify(arr[i], arr[i], dpsuf[i]);
			// std::cerr << "s " << i << " = " << dpsuf[i] << '\n';

			while (!stks.empty() && arr[stks.back()] < arr[i]) {
				int ind = stks.back();
				vs.modify(arr[ind], arr[ind], -dpsuf[ind]);
				stks.pop_back();
			}
			stks.push_back(i);
		}

		for (int i = 1; i < n; i++) {
			res = std::min(res, maxn - 1 - (dppre[i] + dpsuf[i] - 1));
		}
		// std::cerr << "res = " << res << '\n';
		return res;
	};

	std::vector<i64> a1, a2;
	a1.push_back(0), a2.push_back(0);
	for (int i = 1; i <= indn; i++) {
		a1.push_back(a[i]);
	}
	for (int i = n; i >= indn; i--) {
		a2.push_back(a[i]);
	}

	i64 ans = std::min(f(a1), f(a2));

	std::cout << ans << '\n';
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