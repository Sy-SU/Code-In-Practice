#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 l, r;
	int n;
	std::cin >> l >> r >> n;

	auto f = [&](i64 x, i64 y, int n) -> std::string {
		std::string res;

		std::string bx, by;
		while (x) {
			bx.push_back('0' + x % 2);
			x /= 2;
		}

		while (y) {
			by.push_back('0' + y % 2);
			y /= 2;
		}

		std::reverse(bx.begin(), bx.end());
		std::reverse(by.begin(), by.end());

		int lx = bx.size(), ly = by.size();
		// int lcm = lx * ly / std::gcd(lx, ly);

		for (int i = 0; i < n; i++) {
			char now = '0';
			char nx = bx[i % lx], ny = by[i % ly];
			if (nx == '1' && ny == '1') {
				now = '1';
			}

			res.push_back(now);
		}

		return res;
	};

	std::string bl, br;
	i64 _l = l, _r = r;
	while (_l) {
		bl.push_back('0' + _l % 2);
		_l /= 2;
	}

	while (_r) {
		br.push_back('0' + _r % 2);
		_r /= 2;
	}

	std::reverse(bl.begin(), bl.end());
	std::reverse(br.begin(), br.end());

	if (bl.size() == br.size()) {
		int len = bl.size();
		int low = 0;
		for (int i = 0; i < len; i++) {
			if (bl[i] != br[i]) {
				low = len - i;
				break;
			}
		}

		i64 c = l >> low << low;
		// std::cerr << low << '\n';
		i64 x = c + (1 << (low - 1)), y = x - 1;
		assert(l <= y && x <= r);
		// std::cerr << x << " " << y << '\n';
		std::cout << f(x, y, n) << '\n';
	} else if (bl.size() + 1 == br.size()) {
		int lenbl = bl.size();
		i64 x = 1 << lenbl;
		std::cout << f(x, l, n) << '\n';
	} else {
		int lenbr = br.size();
		i64 x = 1 << (lenbr - 2), y = 1 << (lenbr - 1);
		std::cout << f(x, y, n) << '\n';
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