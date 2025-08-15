#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, l, r;
	std::cin >> n >> l >> r;

	std::vector<i64> a(n + 1, 0), pre(n + 1, 0), presum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
		presum[i] = presum[i - 1] + a[i];
	}

	auto calc = [&](auto &&self, i64 x) -> i64 {
		if (x <= n) {
			return a[x];
		}

		i64 to = x / 2;
		// a[1] ^ a[2] ^ ... ^ a[to]
		if (to <= n) {
			return pre[to];
		} else {
			i64 res = pre[n];
			// n + 1 ... to
			if ((n + 1) % 2 == 0) {
				if (to % 2 == 0) {
					return res ^ self(self, to);
				} else {
					return res;
				}
			} else {
				if (to % 2 == 0) {
					return res ^ self(self, n + 1) ^ self(self, to);
				} else {
					return res ^ self(self, n + 1);
				}
				
			}
		}
	};

	auto getpre = [&](auto && self, i64 x) -> i64 {
		if (x <= n) {
			return presum[x];
		}

		i64 res = presum[n];
		// n + 1 ... x
		if (n % 2 == 0) {
			res += a[n + 1];
			n++;
		}
		// n + 1 ... x
		// n + 1 偶数
		if (x % 2 == 0) {
			res += a[x];
			x--;
		}
		// n + 1 ... x

		i64 le = (n + 1) / 2, ri = x / 2;
		return self(self, ri) - self(self, le) + res;
	};

	std::cout << (getpre(getpre, r) - getpre(getpre, l - 1)) << '\n';
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