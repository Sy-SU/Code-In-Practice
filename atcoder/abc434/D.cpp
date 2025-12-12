#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int u, d, l, r;
};

void solve() {
	int n;
	std::cin >> n;

	const int N = 2000;

	std::vector<std::vector<i64>> del(N + 2, std::vector<i64>(N + 2));
	std::vector<Node> node(n + 1);

	for (int i = 1; i <= n; i++) {
		int u, d, l, r;
		std::cin >> u >> d >> l >> r;
		node[i] = {u, d, l, r};

		del[u][l]++, del[u][r + 1]--, del[d + 1][l]--, del[d + 1][r + 1]++;
		
	}

	std::vector<std::vector<i64>> cnt(N + 2, std::vector<i64>(N + 2));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + del[i][j];
		}
	}

	// for (int i = 1; i <= N; i++) {
	// 	for (int j = 1; j <= N; j++) {
	// 		std::cerr << cnt[i][j] << " \n"[j == N];
	// 	}
	// }

	std::vector<std::vector<i64>> one(N + 2, std::vector<i64>(N + 2));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			one[i][j] = one[i - 1][j] + one[i][j - 1] - one[i - 1][j - 1] + (cnt[i][j] == 1);
		}
	}

	i64 res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += cnt[i][j] == 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		auto [u, d, l, r] = node[i];

		std::cout << res + (one[d][r] - one[u - 1][r] - one[d][l - 1] + one[u - 1][l - 1]) << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}