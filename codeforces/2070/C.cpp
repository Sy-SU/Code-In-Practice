#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;
	str = " " + str;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int lo = 0, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {
			std::vector<char> col;
			col.push_back('R');
			for (int i = 1; i <= n; i++) {
				if (a[i] > x) {
					col.push_back(str[i]);
				}
			}

			int cnt = 0;
			for (int i = 1; i < (int)col.size(); i++) {
				cnt += (col[i - 1] == 'R' && col[i] == 'B');
			}
			return cnt <= k;
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
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