#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

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
    i64 add;

    Tag() : add(0) {}
    Tag(i64 x) : add(x) {}

    void apply(const Tag &oth) {
        add += oth.add;
    }
};

struct Info {
    i64 min, max, sum;
    int cnt;

    Info() : min(INF), max(-INF), sum(0), cnt(0) {}
    Info(i64 x) : min(x), max(x), sum(x), cnt(1) {}
    Info(i64 min, i64 max, i64 sum, int cnt) : min(min), max(max), sum(sum), cnt(cnt) {}

    Info operator+(const Info &oth) const {
        return {std::min(min, oth.min), std::max(max, oth.max), sum + oth.sum, cnt + oth.cnt};
    }

    void apply(const Tag &tag) {
        min += tag.add, max += tag.add, sum += cnt * 1ll * tag.add;
    }
};

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	SegmentTree<Info, Tag> st(a);

	while (q--) {
		int o;
		std::cin >> o;

		if (o == 1) {
			int x;
			std::cin >> x;

			auto l = st.query(x, x).sum;
			auto r = st.query(x + 1, x + 1).sum;

			st.modify(x, x, r - l);
			st.modify(x + 1, x + 1, l - r);
		} else {
			int l, r;
			std::cin >> l >> r;

			std::cout << st.query(l, r).sum << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}