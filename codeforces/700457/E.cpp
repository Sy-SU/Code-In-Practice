#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N, n, m;
	std::cin >> N >> n >> m;

	std::vector<i64> del(N + 2);
	std::vector<i64> l(n + 1), r(n + 1), k(n + 1);
	for (int i = 1; i <= n; i++) {
		// int l, r, k;
		std::cin >> l[i] >> r[i] >> k[i];

		del[l[i]] += k[i], del[r[i] + 1] -= k[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += del[i];
		std::cout << sum << " \n"[i == N];
	}

	std::vector<i64> dk(n + 2);
	for (int i = 1; i <= m; i++) {
		int L, R, K;
		std::cin >> L >> R >> K;

		dk[L] += K, dk[R + 1] -= K;
	}

	i64 ds = 0;
	for (int i = 1; i <= n; i++) {
		ds += dk[i];
		k[i] = ds;
	}

	sum = 0;
	for (int i = 1; i <= n; i++) {
		del[l[i]] += k[i], del[r[i] + 1] -= k[i];
	}

	for (int i = 1; i <= N; i++) {
		sum += del[i];
		std::cout << sum << " \n"[i == N];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}