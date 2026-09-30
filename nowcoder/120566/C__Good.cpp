#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

std::map<std::pair<int, int>, bool> vis;

struct Node {
	int l, r;
} node [N << 2];

void build(int u, int l, int r) {
	node[u] = {l, r};
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
	if (!vis.count({node[u].l, node[u].r})) {
		if (l <= node[u].l && node[u].r <= r) {
			return 1;
		}
		int mid = (node[u].l + node[u].r) >> 1;
		int res = 1;
		if (l <= mid) {
			res += query(u << 1, l, r);
		}
		if (r > mid) {
			res += query(u << 1 | 1, l, r);
		}
		return res;
	} else {
		int mid = (node[u].l + node[u].r) >> 1;
		int res = 0;
		if (l <= mid) {
			res += query(u << 1, l, r);
		}
		if (r > mid) {
			res += query(u << 1 | 1, l, r);
		}
		return res;	
	}
}

void solve() {
	int n;
	std::cin >> n;

	build(1, 1, n);
	// std::cerr << "build ok " << '\n';

	for (int i = 1; i <= n; i++) {
		int o, l, r;
		std::cin >> o >> l >> r;

		if (o == 1) {
			vis[{l, r}] = 1;
		} else {
			std::cout << query(1, l, r) << '\n';
		}
	}
}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	solve();

	return 0;
}