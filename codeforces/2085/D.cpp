#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
	int cnt = 0, chs = 0;
	for (int i = n; i >= 1; i--) {
		cnt++;
		if (cnt >= (k + 1) * (chs + 1)) {
			chs++;
			pq.push(d[i]);
		} else if (!pq.empty()){
			i64 min = pq.top();
			if (min < d[i]) {
				pq.pop();
				pq.push(d[i]);
			}
		}
	}

	i64 ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
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