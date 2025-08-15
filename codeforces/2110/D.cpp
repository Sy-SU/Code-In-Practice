#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<std::vector<std::pair<int, i64>>> path(n + 1);
	for (int i = 1; i <= m; i++) {
		int s, t;
		i64 w;
		std::cin >> s >> t >> w;
		path[s].push_back({t, w});
	}

	i64 lo = 1, hi = 1e9;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 max) -> bool {
			std::vector<int> inq(n + 1);
			std::vector<i64> val(n + 1);
			std::queue<int> q;

			q.push(1);
			val[1] = std::min(max, b[1]);
			inq[1] = 1;

			while (!q.empty()) {
				int now = q.front();
				if (now == n) {
					return 1;
				}
				i64 cost = val[now];
				q.pop();

				inq[now] = 0;

				for (const auto &[to, w] : path[now]) {
					if (w > cost) {
						continue;
					}
					val[to] = std::min(max, val[now] + b[to]);
					if (!inq[to]) {
						inq[to] = 1;
						q.push(to);
					}
				}
			}

			return 0;
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
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