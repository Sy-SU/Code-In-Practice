#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 200 + 10;

int mat[N][N];

void solve() {
	int n;
	std::cin >> n;

	const int maxn = 200;

	for (int i = 1; i <= maxn; i++) {
		mat[i][i] = 1;
	}

	for (int i = 1; i <= maxn; i += 3) {
		mat[i][1] = n % 2;
		n /= 2;
		mat[i][i + 1] = mat[i][i + 2] = mat[i + 1][i + 1] = mat[i + 1][i + 3] = mat[i + 2][i + 2] = mat[i + 2][i + 3] = 1;
	}

	for (int i = 1; i <= maxn; i++) {
		for (int j = 1; j <= maxn; j++) {
			std::cout << mat[i][j] << " \n"[j == maxn];
		}
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}