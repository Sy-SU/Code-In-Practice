#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<int, int> map;
	for (int i = 1; i <= n; i++) {
		map[a[i]]++;
	}

	int ans = 0;
	for (const auto& [num, cnt]: map) {
		if (cnt && cnt % 2) {
			ans++;
		} else if (cnt && cnt % 2 == 0) {
			ans += 2;
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