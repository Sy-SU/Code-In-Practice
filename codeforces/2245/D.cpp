#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);

	std::map<std::pair<int, int>, int> f;
	for (int i = 1; i <= m; i++) {
		int o, x, y;
		std::cin >> o >> x >> y;

		f[{x, y}] = o;
		if (x == y) {
			a[x] = (o == 1 ? 1 : -1);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (f[{j, i}] == 1) {
				if (a[i] == -1 && a[j] == -1) {
					std::cout << "NO" << '\n';
					return;
				}
			} else {
				if (a[i] == 1 && a[j] == 1) {
					std::cout << "NO" << '\n';
					return;
				}
			}
		}
	}

	std::vector<int> inq(n + 1), d(n + 1);
	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[i] == a[j]) {
				continue;
			}
			if (f[{j, i}] == 1) {
				if (a[i] == 1) {
					adj[i].push_back(j);
					d[j]++;
				} else {
					adj[j].push_back(i);
					d[i]++;
				}
			} else {
				if (a[i] == -1) {
					adj[i].push_back(j);
					d[j]++;
				} else {
					adj[j].push_back(i);
					d[i]++;
				}
			}
		}
	}

	std::vector<int> vec;
	std::queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			inq[i] = 1, q.push(i);
		}
	}

	while (!q.empty()) {
		auto now = q.front();
		vec.push_back(now);
		q.pop();

		for (auto to : adj[now]) {
			d[to]--;
			if (d[to] == 0) {
				inq[to] = 1;
				q.push(to);
			}
		}
	}

	if (vec.size() != n) {
		std::cout << "NO" << '\n';
		return;
	}

	std::vector<int> p(n + 1);
	int ind = n;
	for (auto id : vec) {
		p[id] = ind;
		ind--;
	}

	std::cout << "YES" << '\n';
	for (int i = 1; i <= n; i++) {
		std::cout << a[i] * p[i] << " \n"[i == n];
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