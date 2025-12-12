#include <bits/stdc++.h>

using i64 = long long;

template<class Info, class Tag>
struct SegmentTree {
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
    	if (tag[u].add != -1) {
    		apply(u << 1, tag[u]), apply(u << 1 | 1, tag[u]);
    	}
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

    Tag() : add(-1) {}
    Tag(i64 x) : add(x) {}

    void apply(const Tag &oth) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        add = oth.add;
    }
};

struct Info {
    // 需要维护的信息，例如区间和，区间最值
    i64 sum;
    int cnt; // 区间长度

    Info() : sum(0), cnt(0) {}
    Info(i64 x) : sum(x), cnt(1) {}
    Info(i64 sum, int cnt) : sum(sum), cnt(cnt) {}

    Info operator+(const Info &oth) const {
        return {sum + oth.sum, cnt + oth.cnt};
    }

    void apply(const Tag &tag) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        sum = cnt * 1ll * tag.add;
    }
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> v(n + 1);
	std::vector<int> a(n + 1), b(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		b[x] = i;
	}

	std::vector<i64> pv(n + 1);
	std::vector<int> pa(n + 1);

	for (int i = 1; i <= n; i++) {
		pv[b[i]] = v[i], pa[i] = b[a[i]];
	}

	v = pv, a = pa;

	std::vector<i64> tmp(n + 1);
	SegmentTree<Info, Tag> st(tmp);

	for (int i = n; i >= 1; i--) {
		if (v[a[i]] >= 0) {
			st.modify(a[i], a[i], v[a[i]]);
		} else {
			i64 del = 0;
			del += st.query(1, a[i]).sum;

			if (-v[a[i]] <= del) {
				st.modify(a[i], a[i], v[a[i]]);
			} else {
				st.modify(1, a[i], 0);
			}
		}

		if (st.query(1, n).sum < 0) {
			st.modify(1, n, 0);
		}
	}
	std::cout << st.query(1, n).sum << '\n';
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