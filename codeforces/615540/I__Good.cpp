#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	i64 k;
	std::cin >> k;

	std::vector<std::pair<i64, i64>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 s, t;
		std::cin >> s >> t;

		vec[i] = {s, s + t};
	}

	std::sort(vec.begin() + 1, vec.end());


	int lo = 1, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {		
			std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;

			for (int i = 1; i <= n; i++) {
				if (pq.size() < x) {
					pq.push(vec[i].second);
				} else {
					i64 now = pq.top();
					pq.pop();

					if (now - vec[i].first > k) {
						return 0;
					}

					i64 delay = std::max(now - vec[i].first, 0ll);
					pq.push(vec[i].second + delay);
				}
			}
			return 1;
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
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}