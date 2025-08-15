#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 4e5 + 10;

int w[N], _w[N];

std::vector<int> edge[N];

int dfn[N], idx, dfl[N], dfr[N];

void dfs(int u, int fa) {
	dfn[u] = ++idx;
	dfl[u] = idx;
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
	}
	dfr[u] = idx;
}

std::map<int, int> al, ar;

void solve() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
		_w[i] = w[i];
		edge[i].clear();
		al[i] = 1e9, ar[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::sort(_w + 1, _w + n + 1, std::greater<int>());
	int target = -1;
	for (int i = 1; i <= n; i++) {
		if (_w[i] != _w[1]) {
			target = _w[i];
			break;
		}
	}
	if (target == -1) {
		std::cout << 0 << '\n';
		return;
	}

	idx = 0;

	dfs(1, -1);

	int l = 1e9, r = 0;
	for (int i = 1; i <= n; i++) {
		if (w[i] == _w[1]) {
			l = std::min(l, dfn[i]), r = std::max(r, dfn[i]);
		}
		al[w[i]] = std::min(al[w[i]], dfn[i]), ar[w[i]] = std::max(ar[w[i]], dfn[i]);
	}

	std::vector<int> vecl, vecr;
	for (const auto &[ind, val] : al) {
		vecl.push_back(ind);
	}

	for (const auto &[ind, val] : ar) {
		vecr.push_back(ind);
	}

	for (int i = (int)vecl.size() - 2; i >= 0; i--) {
		al[vecl[i]] = std::min(al[vecl[i]], al[vecl[i + 1]]);
		//std::cerr << "ar" << vecl[i] << " = " << ar[vecl[i]] << '\n';
	}

	for (int i = (int)vecl.size() - 2; i >= 0; i--) {
		ar[vecr[i]] = std::max(ar[vecr[i]], ar[vecr[i + 1]]);
		//std::cerr << "ar" << vecl[i] << " = " << ar[vecl[i]] << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if ((l < dfl[i] || r > dfr[i]) && (dfl[i] <= al[w[i]] && ar[w[i]] <= dfr[i])) {
			std::cout << i << '\n';
			return;
		}
	}
	std::cout << 0 << '\n';
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