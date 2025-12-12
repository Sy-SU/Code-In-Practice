#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int l, r;
	std::cin >> l >> r;
	
	auto calc = [&](int x) -> int {
		std::vector<int> a;
		int tmp = x;
		while (tmp) {
			a.push_back(tmp % 2);
			tmp /= 2;
		}

		int len = a.size();

		std::vector<std::vector<std::vector<int>>> f(40, std::vector<std::vector<int>>(40, std::vector<int>(40, -1)));
		// f[pos][cnt0][cnt1]

		auto dfs = [&](auto &&self, int pos, bool limit, bool lead0, int cnt0, int cnt1) -> int {
			if (pos == -1) {
				return cnt1 <= cnt0;
			}

			if (!limit && !lead0 && f[pos][cnt0][cnt1] != -1) {
				return f[pos][cnt0][cnt1];
			}

			int res = 0, up = (limit ? a[pos] : 1);
			for (int i = 0; i <= up; i++) {
				res += self(self, pos - 1, limit && (a[pos] == i), lead0 && (i == 0), cnt0 + (!lead0 && (i == 0)), cnt1 + (i == 1));
			}

			if (!limit && !lead0) {
				f[pos][cnt0][cnt1] = res;
			}

			return res;
		};

		return dfs(dfs, len - 1, 1, 1, 0, 0); 
	};

	std::cout << calc(r) - calc(l - 1) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}