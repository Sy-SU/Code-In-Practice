#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	std::vector<std::vector<i64>> f(n + 1, std::vector<i64>(32));
	for (int i = 1; i <= n; i++) {
		f[i][0] = a[i];
	}
	for (int j = 1; j <= log(n) / log(2); j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) { // 维护静态区间最大值
			f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}

	auto q = [&](int l, int r) -> i64 {
		int x = log(r - l + 1) / log(2);
		return std::max(f[l][x], f[r - (1 << x) + 1][x]);
	};

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cnt += q(i, j) * 2 == (pre[j] - pre[i - 1]);
		}
	}
	std::cout << cnt << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}