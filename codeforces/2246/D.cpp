#include <bits/stdc++.h>

using i64 = long long;

i64 ans[1000005];

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	if (n == 1) {
		i64 minans = 1e18;
		for (int x = 0; x <= 20; x++) {
			minans = std::min(minans, x + ans[x + a[1]]);
		}
		std::cout << minans << '\n';
		return;
	}

	i64 minans = 1e18;

	for (int i = 0; i <= 18; i++) {
		i64 num = 1 << i;
		i64 tans = i;
		std::vector<int> b(n + 1);

		for (int j = 1; j <= n; j++) {
			i64 tar = -1;
			if (a[j] % num == 0) {
				tar = a[j];
			} else {
				i64 res = a[j] % num;
				tar = a[j] + num - res;
			}
			i64 min = 1e18;
			for (int m = 0; m <= 40; m++) {
				// tar + m * num
				min = std::min(min, tar + m * num - a[j] + ans[m + tar / num]);
			}
			tans += min;
		}
		minans = std::min(minans, tans);
	}
	std::cout << minans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 1; i <= 1000000; i++) {
		int to = -1;
		if (i % 2) {
			to = i - 1;
		} else {
			to = i / 2;
		}

		ans[i] = ans[to] + 1;
	}

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}