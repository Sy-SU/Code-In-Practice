#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a;
	int tmp = n;
	while (tmp) {
		a.push_back(tmp % 10);
		tmp /= 10;
	}

	int len = a.size();

	std::vector<std::vector<int>> f(20, std::vector<int>(200, -1));

	auto dfs = [&](auto &&self, int pos, bool limit, i64 sum) -> i64 {
		if (pos == -1) {
			return sum;
		}

		if (!limit && f[pos][sum] != -1) {
			return f[pos][sum];
		}

		i64 res = 0;
		int up = limit ? a[pos] : 9;

		for (int i = 0; i <= up; i++) {
			res += self(self, pos - 1, limit && (i == a[pos]), sum + i);
		}

		if (!limit) {
			f[pos][sum] = res;
		}

		return res;
	};

	std::cout << dfs(dfs, len - 1, 1, 0) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}