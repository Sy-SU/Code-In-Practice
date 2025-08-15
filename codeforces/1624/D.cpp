#include <bits/stdc++.h>

using i64 = long long;
#define int long long

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	std::map<char, int> cnt;
	for (const auto &ch : str) {
		cnt[ch]++;
	}

	int pair = 0, single = 0;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		pair += cnt[ch] / 2, single += cnt[ch] % 2;
	}

	int lo = 1, hi = n;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {
			// 长度为 x 
			if (x % 2 == 0) {
				x /= 2;
				if (pair < x * k) {
					return 0;
				} else {
					return 1;
				}
			} else {
				x /= 2;
				if (pair < x * k) {
					return 0;
				} else {
					if (single + (pair * 2 - x * k * 2) < k) {
						return 0;
					} else {
						return 1;
					}
				}
			}
		};

		if (check(mid)) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}