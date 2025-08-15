#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 a, b, m, s;
	std::cin >> a >> b >> m >> s;

	if (b >= s) {
		std::cout << "YES" << '\n';
		return;
	}

	i64 cnt = (s - b + m - 1) / m;

	std::cout << (cnt <= a && cnt * m <= s ? "YES" : "NO") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}