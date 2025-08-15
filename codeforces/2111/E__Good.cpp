#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string str;
	std::cin >> str;

	std::vector<std::pair<char, char>> op;

	for (int i = 1; i <= q; i++) {
		char x, y;
		std::cin >> x >> y;

		op.push_back({x, y});
	}

	std::string ans = str;

	int sit = pow(n + 1, q);
	for (int s = 0; s < sit; s++) {
		int now = s;
		std::string t = str;

		bool valid = 1;

		for (int i = 0; i < q; i++) {
			int ind = now % (n + 1);
			if (ind != n) {
				if (t[ind] != op[i].first) {
					valid = 0;
				}
				t[ind] = op[i].second;
			}

			now /= (n + 1);
		}

		if (valid) {
			ans = std::min(ans, t);
		}
	}

	std::cout << ans << '\n';
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