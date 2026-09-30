#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

std::map<std::pair<int, int>, int> func;

struct Node {
	int l, r;
	int cost;
	bool ok;
} node [N << 2];

void build(int u, int l, int r) {
	node[u] = {l, r, 1, 1};
	func[{l, r}] = u;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
	// std::cerr << "vis" << l << " " << r << '\n';
	if (node[u].ok) { // 没有被损坏
		if (l <= node[u].l && node[u].r <= r) {
			return node[u].cost;
		}
		int mid = (node[u].l + node[u].r) >> 1;
		int res = 1;
		if (l <= mid) {
			res += query(u << 1, l, r);
			// std::cerr << "u = " << u << " " << res << '\n';
		}
		if (r > mid) {
			res += query(u << 1 | 1, l, r);
			// std::cerr << "u = " << u << " " << res << '\n';
		}
		return res;
	} else {
		if (l <= node[u].l && node[u].r <= r) {
			return node[u].cost;
		}
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

int pushdown(int u) {
	int mid = (node[u].l + node[u].r) >> 1;
	return query(u << 1, node[u].l, mid) + query(u << 1 | 1, mid + 1, node[u].r);
}

void pushup(int u) {
	int mid = (node[u].l + node[u].r) >> 1;
	node[u].cost = query(u << 1, node[u].l, mid) + query(u << 1 | 1, mid + 1, node[u].r);
}

void modify(int l, int r) {
	int u = func[{l, r}];
	node[u].ok = 0;
	node[u].cost = pushdown(u);
	while (u) {
		u = u >> 1;
		if (node[u].ok) {
			return;
		}
		pushup(u);
	}
	// std::cerr << node[u].l << " " << node[u].r << ".cost = " << node[u].cost << '\n';
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
			// vis[{l, r}] = 1;
			modify(l, r);
		} else {
			std::cout << query(1, l, r) << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}