#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::map<int, int> s;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		s[x] = 1;
	}

	std::vector<int> a;
	for (auto [x, _] : s) {
		a.push_back(x);
	}

	std::sort(a.begin(), a.end(), std::greater<int>());

	int ans = 0;
	n = a.size();

	std::vector<int> cho;
	for (int i = 0; i < n; i++) {
		bool isok = 1;
		if (cho.size() == 3) {
			isok = 0;
		}
		for (auto num : cho) {
			if (num % a[i] == 0 || a[i] % num == 0) {
				isok = 0;
			}
		}

		if (isok) {
			cho.push_back(a[i]);
			ans += a[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] % 30 == 0) {
			if (s[a[i] / 2] && s[a[i] / 3] && s[a[i] / 5]) {
				ans = std::max(ans, a[i] / 30 * 31);
			}
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