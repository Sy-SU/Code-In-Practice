#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct SEGTREE {
	struct NODE {
		unsigned int mask;
		int lazy;
	};

	int n;
	std::vector<NODE> tree;

	SEGTREE(const std::string &s) {
		n = s.size();
		tree.resize(n << 2);
		build(1, 1, n, s);
	}

	unsigned int rotate(unsigned int mask, int d) {
		if (d == 0) {
			return mask;
		}
		return ((mask << d) | (mask >> (26 - d))) & ((1u << 26) - 1);
	}

	void pushup(int p) {
		tree[p].mask = tree[p << 1].mask ^ tree[p << 1 | 1].mask;
	}

	void build(int p, int l, int r, const std::string &s) {
		tree[p].lazy = 0;
        if (l == r) {
            tree[p].mask = 1u << (s[l - 1] - 'a');
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, s);
        build(p << 1 | 1, mid + 1, r, s);
        pushup(p);
	}

	void shift(int p, int d) {
		tree[p].mask = rotate(tree[p].mask, d);
		tree[p].lazy = (tree[p].lazy + d) % 26;
	}

	void pushdown(int p) {
		int d = tree[p].lazy;
		if (d == 0) {
			return;
		}

		shift(p << 1, d), shift(p << 1 | 1, d);
		tree[p].lazy = 0;
	}

	void range_shift(int p, int l, int r, int L, int R, int d) {
		if (L <= l && r <= R) {
			shift(p, d);
			return;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		if (L <= mid) {
			range_shift(p << 1, l, mid, L, R, d);
		}
		if (R > mid) {
			range_shift(p << 1 | 1, mid + 1, r, L, R, d);
		}
		pushup(p);
	}

	unsigned int query_range(int p, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return tree[p].mask;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		unsigned int res = 0;
		if (L <= mid) {
			res ^= query_range(p << 1, l, mid, L, R);
		}
		if (R > mid) {
			res ^= query_range(p << 1 | 1, mid + 1, r, L, R);
		}
		return res;
	}

	void range_shift(int l, int r, int d) {
		range_shift(1, 1, n, l, r, d);
	}

	unsigned int query_range(int l, int r) {
		return query_range(1, 1, n, l, r);
	}
};

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string str;
	std::cin >> str;

	SEGTREE segtree(str);

	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r, d;
			std::cin >> l >> r >> d;

			segtree.range_shift(l, r, d % 26);
		} else {
			int l, r;
			std::cin >> l >> r;

			unsigned int ans = segtree.query_range(l, r);
			std::cerr << ans << '\n';
			int cnt = 0;
			while (ans) {
				cnt += ans % 2;
				ans /= 2;
			}

			std::cout << (cnt <= 1 ? "Yes" : "No") << '\n';
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