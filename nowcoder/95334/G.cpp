#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, m;
	std::cin >> n >> m;

	if (m == 1) {
		std::cout << 1 << '\n';
		return;
	}

	i64 now = m, cnt = 1;
	i64 mindel = 1e16, anscnt = -1;
	while (1) {
		if (mindel > std::abs(now - n)) {
			mindel = std::abs(now - n);
			anscnt = cnt;
		}
		if (now > n) {
			break;
		}
		now *= m, cnt++;
	}
	std::cout << anscnt << '\n';
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