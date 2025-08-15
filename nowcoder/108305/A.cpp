#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

std::ostream &operator<<(std::ostream &os, __uint128_t n) {
	if (n > 9) {
		os << n / 10;
	}
	os << (int)(n % 10);
	return os;
}
std::ostream &operator<<(std::ostream &os, __int128_t n) {
	if (n < 0) {
		os << '-';
		n = -n;
	}
	return os << (__uint128_t)n;
}

void solve() {
	i64 x;
	std::cin >> x;

	if (x < 0) {
		i128 a = x;
		a = -a;
		i128 ans = 1e30, base = 1;
		for (int i = 0; i < 30; i++) {
			i128 tmp = (a / base * base * 10) + base + a % base;
			if (base > a * 10) {
				break;
			}
			base *= 10;
			ans = std::min(ans, tmp);
		}
		std::cout << -ans << '\n';
	} else if (x > 0) {
		i128 a = x;
		i128 ans = -1e30, base = 1;
		for (int i = 0; i < 30; i++) {
			i128 tmp = (a / base * base * 10) + base + a % base;
			if (base > a * 10) {
				break;
			}
			base *= 10;
			ans = std::max(ans, tmp);
		}
		std::cout << ans << '\n';
	} else {
		std::cout << 10 << '\n';
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