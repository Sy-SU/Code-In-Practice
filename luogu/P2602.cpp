#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b;
	std::cin >> a >> b;

	auto calc = [&](i64 x, int d) -> i64 {
		// 小于等于 x 的数中 d 出现了多少次
		int len = 0;
		i64 tmp = x;
		std::vector<int> a;
		while (tmp) {
			len++;
			a.push_back(tmp % 10);
			tmp /= 10;
		} // 12345 -> {5, 4, 3, 2, 1}

		std::vector<std::vector<i64>> f(20, std::vector<i64>(20, -1));

		auto dfs = [&](auto &&self, int pos, bool limit, i64 ans, bool lead0) -> i64 {
			if (pos == -1) {
				return ans;
			}

			if (!limit && !lead0 && f[pos][ans] != -1) {
				return f[pos][ans];
			}

			i64 res = 0;

			if (limit) {
				for (int digit = 0; digit < a[pos]; digit++) {
					res += self(self, pos - 1, 0, ans + ((d == 0 && digit == 0 && lead0 == 1) ? 0 : (digit == d)), lead0 && (digit == 0));	
				}
				res += self(self, pos - 1, 1, ans + ((d == 0 && a[pos] == 0 && lead0 == 1) ? 0 : (a[pos] == d)), lead0 && (a[pos] == 0));
			} else {
				for (int digit = 0; digit <= 9; digit++) {
					res += self(self, pos - 1, 0, ans + ((d == 0 && digit == 0 && lead0 == 1) ? 0 : (digit == d)), lead0 && (digit == 0));
				}
			}

			if (!limit && !lead0) {
				f[pos][ans] = res;
			}

			return res;
		};

		return dfs(dfs, len - 1, 1, 0, 1);
	};

	for (int d = 0; d <= 9; d++) {
		std::cout << calc(b, d) - calc(a - 1, d) << " \n"[d == 9];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}