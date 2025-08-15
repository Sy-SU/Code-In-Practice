#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int pre[30][N];

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;
	str = " " + str;

	for (int i = 1; i <= n; i++) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			pre[ch - 'a'][i] = pre[ch - 'a'][i - 1] + (ch == str[i]);
		}
	}

	int lo = 2, hi = n - 1;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			for (int i = 1; i + mid - 1 <= n; i++) {
				if (pre[str[i] - 'a'][i - 1] - pre[str[i] - 'a'][0] != 0) {
					return 1;
				}
				if (pre[str[i + mid - 1] - 'a'][n] - pre[str[i + mid - 1] - 'a'][i + mid - 1] != 0) {
					return 1;
				}
			}
			return 0;
		};

		if (check()) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	assert(ans >= n - 30);
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}