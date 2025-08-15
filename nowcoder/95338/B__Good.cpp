#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::pair<i64, i64> vec[N];

void solve() {
	int n;
	i64 c[2];
	std::cin >> n >> c[0] >> c[1];

	for (int i = 1; i <= n; i++) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	int con = 1;
	for (int i = 1; i <= n; i++) {
		con *= 3;
	}

	i64 ans = 1e16;

	for (int cc = 0; cc < con; cc++) {
		int tmp = cc;
		std::vector<std::pair<i64, i64>> op;
		i64 cost = 0;
		for (int i = 1; i <= n; i++) {
			if (tmp % 3 == 0) {
				op.push_back({vec[i].first, vec[i].second});
			} else if (tmp % 3 == 1) {
				op.push_back({vec[i].second, vec[i].first});
				cost += c[1];
			} else {
				cost += c[0];
			}

			tmp /= 3;
		}

		bool isok = 1;
		for (int i = 1; i < (int)op.size(); i++) {
			if (op[i].first < op[i - 1].first || op[i].second < op[i - 1].second) {
				isok = 0;
				break;
			}
		}
		if (isok) {
			ans = std::min(ans, cost);
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