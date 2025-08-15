#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 t;
	std::cin >> t;

	i64 sqt = sqrtl(t);
	if (sqt % 2 == 0) {
		sqt--;
	}

	i64 sta1 = sqt * sqt, sta2 = sqt * (sqt + 1), sta3 = (sqt + 1) * (sqt + 1), sta4 = (sqt + 1) * (sqt + 2);
	if (sta1 == t) {
		std::cout << (sqt - 1) / 2 << " " << (sqt - 1) / 2 << '\n';
	} else if (t <= sta2) {
		std::cout << (sqt - 1) / 2 + 1 << " " << (sqt - 1) / 2 - (t - sta1 - 1) << '\n';
	} else if (t <= sta3) {
		std::cout << (sqt - 1) / 2 + 1 - (t - sta2 - 1) << " " << -((sqt - 1) / 2 + 1) << '\n';
	} else if (t <= sta4) {
		std::cout << -((sqt - 1) / 2 + 1) << " " << -((sqt - 1) / 2 + 1) + (t - sta3 - 1) << '\n';
	} else {
		std::cout << -((sqt - 1) / 2 + 1) + (t - sta4 - 1) << " " << ((sqt - 1) / 2 + 1) << '\n';
	}
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