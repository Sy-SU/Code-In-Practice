#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 10;

i64 dp[N][30][2][2];

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> p2(40);
	p2[0] = 1;
	for (int i = 1; i < 30; i++) {
		p2[i] = p2[i - 1] * 2;
	}

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int b = 0; b < 30; b++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					dp[i][b][k][l] = dp[i - 1][b][k][l];
				}
			}
		}
		int x = 0;
		for (int b = 0; b < 30; b++) {
			int now = (a[i] >> b) & 1;
			dp[i][b][now][x] = dp[i - 1][b][now][x] + 1;
			x ^= now;
		}
	}	
	
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		int ans[2][2] = {0};
		int tag = 0, lsttag = 0;
		for (int b = 0; b < 30; b++) {
			int now = (a[i] >> b) & 1;
			tag = now;
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					ans[k][l] = dp[n][b][k ^ tag][l ^ lsttag];
				}
			}
			sum += p2[b] * ans[1][0];
			lsttag ^= tag;
		}	
	}
	std::cout << sum / 2 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// 514228

	solve();

	return 0;
}