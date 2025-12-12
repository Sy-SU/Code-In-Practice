#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		cnt[x]++;
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (cnt[i] == 0) {
			continue;
		}
		if (i < cnt[i]) {
			ans += cnt[i] - i;
		} else if (i > cnt[i]) {
			ans += cnt[i];
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