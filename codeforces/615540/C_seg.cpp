#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

int a[N], tree[N];

struct NODE {
	int l, r;
	i64 sum, lazy;
} node[N << 2];

void pushup(int u) {
	node[u].sum = node[u << 1].sum + node[u << 1 | 1].sum;
}

void pushdown(int u) {
	if (node[u].lazy) {
		node[u << 1].sum = node[u].lazy * (node[u << 1].r - node[u << 1].l + 1);
		node[u << 1 | 1].sum = node[u].lazy * (node[u << 1 | 1].r - node[u << 1 | 1].l + 1);
		node[u << 1].lazy = node[u].lazy;
		node[u << 1 | 1].lazy = node[u].lazy;
		node[u].lazy = 0;
	}
}

void build(int u, int l, int r) {
	node[u] = {l, r, tree[l], 0ll};
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, i64 val) {
	if (l <= node[u].l && node[u].r <= r) {
		node[u].sum = val * (node[u].r - node[u].l + 1);
		node[u].lazy = val;
		return;
	}
	int mid = (node[u].l + node[u].r) >> 1;
	pushdown(u);
	if (l <= mid) {
		update(u << 1, l, r, val);
	}
	if (r > mid) {
		update(u << 1 | 1, l, r, val);
	}
	pushup(u);
}

i64 getsum(int u, int l, int r) {
	if (l <= node[u].l && node[u].r <= r) {
		return node[u].sum;
	}
	int mid = (node[u].l + node[u].r) >> 1;
	pushdown(u);
	i64 sum = 0;
	if (l <= mid) {
		sum += getsum(u << 1, l, r);
	}
	if (r > mid) {
		sum += getsum(u << 1 | 1, l, r);
	}
	return sum;
}

void update(int l, int r, i64 val) {
	update(1, l, r, val);
}

i64 getPoint(int p) {
	return getsum(1, p, p);
}

std::vector<int> edge[N];

std::vector<std::pair<int, int>> range(N);

int d;

int d1[N], d2[N];

void dfs(int u, int fa) {
	d1[u] = d2[u] = 0;
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		int t = d1[v] + 1;
		if (t > d1[u]) {
			d2[u] = d1[u], d1[u] = t;
		} else if (t > d2[u]) {
			d2[u] = t;
		}
	}
	d = std::max(d, d1[u] + d2[u]);
}

void solve() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		tree[i] = a[1];
	}

	range[a[1]] = {1, n};

	build(1, 1, n);

	for (int i = 2; i <= n; i++) {
		int fa = getPoint(a[i]);
		edge[fa].push_back(a[i]), edge[a[i]].push_back(fa);
		// std::cerr << fa << "<->" << a[i] << '\n';

		auto [l, r] = range[fa];

		if (a[i] < fa) {
			range[fa] = {fa, r};

			update(l, fa - 1, a[i]);
			range[a[i]] = {l, fa - 1};
		} else {
			range[fa] = {l, fa};

			update(fa + 1, r, a[i]);
			range[a[i]] = {fa + 1, r};
		}
	}

	dfs(1, -1);

	std::cout << d << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}