#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s, t;
	std::cin >> s >> t;

	if (n <= k) {
		std::cout << (s == t ? "YES" : "NO") << '\n';
		return;
	}

	if (n == k + 1) {
		if (s == t) {
			std::cout << "YES" << '\n';
			return;
		}

		std::swap(s[0], s[n - 1]);
		std::cout << (s == t ? "YES" : "NO") << '\n';
		return;
	}

	if (n == k + 2) {
		if (s[2] != t[2]) {
			std::cout << "NO" << '\n';
			return;
		}
	}

	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	std::cout << (s == t ? "YES" : "NO") << '\n';
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