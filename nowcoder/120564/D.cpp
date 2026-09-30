#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	i128 d = exgcd(b, a % b, x, y);
	i128 t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
}

void solve() {
	i64 c, a, b;
	std::cin >> c >> a >> b;

	if (c % std::gcd(a, b)) {
		std::cout << "No" << '\n';
		return;
	}

	i128 x, y;
	i128 d = exgcd(a, b, x, y);
	i128 k = c / d;
	x *= k, y *= k;

	i128 _b = b / std::__gcd(a, b), _a = a / std::__gcd(a, b);
	i128 p = -x / _b - 5, q = y / _a + 5;

	// std::cerr << p << " " << q << '\n';

	// if (p > q) {
	// 	if (c % a == 0) {
	// 		std::cout << "Yes" << '\n';
	// 		std::cout << c / a << " " << 0 << '\n';
	// 		return;
	// 	} else if (c % b == 0) {
	// 		std::cout << "Yes" << '\n';
	// 		std::cout << 0 << " " << c / b << '\n';
	// 		return;
	// 	}
	// 	std::cout << "No" << '\n';
	// 	return;
	// }

	i128 bt = (y - x) / (_a + _b);

	i128 min = 9e18;
	i128 bestt = -9e18;
	for (i128 t = -10 + bt; t <= 10 + bt; t++) {
		if (t < p || t > q) {
			continue;
		}
		if (x + _b * t < 0 || y - _a * t < 0) {
			continue;
		}
		// std::cerr << (i64)(x + _b * t) << " " << (i64)(y - _a * t) << '\n';
		if (std::max(x + _b * t, y - _a * t) < min) {
			min = std::max(x + _b * t, y - _a * t);
			bestt = t;
		}
	}

	for (i128 t = p; t <= p + 10; t++) {
		if (t < p || t > q) {
			continue;
		}
		if (x + _b * t < 0 || y - _a * t < 0) {
			continue;
		}
		// std::cerr << (i64)(x + _b * t) << " " << (i64)(y - _a * t) << '\n';
		if (std::max(x + _b * t, y - _a * t) < min) {
			min = std::max(x + _b * t, y - _a * t);
			bestt = t;
		}
	}

	for (i128 t = q - 10; t <= q; t++) {
		if (t < p || t > q) {
			continue;
		}
		if (x + _b * t < 0 || y - _a * t < 0) {
			continue;
		}
		// std::cerr << (i64)(x + _b * t) << " " << (i64)(y - _a * t) << '\n';
		if (std::max(x + _b * t, y - _a * t) < min) {
			min = std::max(x + _b * t, y - _a * t);
			bestt = t;
		}
	}

	if (bestt == -9e18) {
		std::cout << "No" << '\n';
		return;
	}

	// std::cerr << p << " " << bt << " " << q << '\n';

	std::cout << "Yes" << '\n';
	std::cout << (i64)(x + _b * bestt) << " " << (i64)(y - _a * bestt) << '\n';
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