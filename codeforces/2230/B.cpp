#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	// 4 12 32

	int cnt4 = 0, sum2 = 0;
	for (auto ch : s) {
		if (ch == '4') {
			cnt4++;
		}
		if (ch == '2') {
			sum2++;
		}
	}

	int ans = 1e9;

	int cnt13 = 0, cnt2 = 0;
	for (auto ch : s) {
		if (ch == '2') {
			cnt2++;
		}
		ans = std::min(ans, cnt4 + sum2 - cnt2 + cnt13);
		if (ch == '1' || ch == '3') {
			cnt13++;
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