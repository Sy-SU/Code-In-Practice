#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e3 + 10;

int a[N][N], del[N][N];

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
			del[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
		}
	}
	*/
	
	while (m--) {
		int i, j, x, y;
		std::cin >> i >> j >> x >> y;
		del[i][j]++, del[x + 1][j]--, del[i][y + 1]--, del[x + 1][y + 1]++;
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + del[i][j];
			std::cout << a[i][j] << " \n"[j == n];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
