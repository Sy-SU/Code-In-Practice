#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int ans[2510][2510];

void solve() {
	int n;
	std::cin >> n;

	int p;
	for (int i = n + 1; ; i++) {
		int now = i;
		bool isok = 1;
		for (int x = 2; x * x <= now; x++) {
			if (now % x == 0) {
				isok = 0;
				break;
			}
		}

		if (isok) {
			p = i;
			break;
		}
	}

	ans[0][1] = -p + 1;

	for (int i = 1; i <= n; i++) {
		int now = ans[i - 1][1] + p;
		for (int j = 1; j <= n; j++) {
			ans[i][j] = now;
			now++;
		}
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << ans[i][j] << " \n"[j == n];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}