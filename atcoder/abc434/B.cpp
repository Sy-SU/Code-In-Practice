#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> sum(m + 1), cnt(m + 1);
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;

		cnt[a]++, sum[a] += b;
	}

	for (int i = 1; i <= m; i++) {
		std::cout << std::fixed << std::setprecision(10) << sum[i] * 1.0 / cnt[i] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}