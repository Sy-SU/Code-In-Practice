#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 2; i <= n; i++) {
		int p;
		std::cin >> p;

		adj[p].push_back(i);
	}

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::pair<int, int>> val(n + 1);

	bool ok = 1;

	auto dfs = [&](auto &&self, int u, int f) -> void {
		if (a[u]) {
			val[u].first = val[u].second = a[u];
			return;
		} else {
			val[u].first = 1e9, val[u].second = -1e9;
		}

		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}

		std::vector<std::pair<int, int>> ve;
		for (auto v : adj[u]) {
			ve.push_back(val[v]);
		}

		int sz = ve.size();
		std::vector<std::pair<int, int>> seq;

		int l = 0;
		for (int i = 1; i < sz; i++) {
			if (ve[i].first > ve[i - 1].second) {
				continue;
			}

			seq.push_back({l, i - 1});
			l = i;
		}
		seq.push_back({l, sz - 1});

		if (seq.size() >= 3) {
			ok = 0;
			return;
		}
		if (seq.size() == 1) {
			val[u].first = ve[0].first;
			val[u].second = ve[sz - 1].second;
			return;
		}
		if (ve[seq[1].second].second > ve[seq[0].first].first) {
			ok = 0;
		}
		val[u].first = ve[seq[1].first].first;
		val[u].second = ve[seq[0].second].second;
	};

	dfs(dfs, 1, 0);

	std::cout << (ok ? "YES" : "NO") << '\n';
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