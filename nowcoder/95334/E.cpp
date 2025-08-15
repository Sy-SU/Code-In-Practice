#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

i64 arr[N], a[N], pre[N];

i64 Sparse_Table_f[N][30];

i64 query(int l, int r)
{
	// 查询区间最大值
	int x = log(r - l + 1) / log(2);
	return std::max(Sparse_Table_f[l][x], Sparse_Table_f[r - (1 << x) + 1][x]);
}

void solve() {
	int n, q;
	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	for (int i = 1; i < n; i++) {
		arr[i] = a[i + 1] - pre[i];
	}

	// 初始化 ST 表
	for (int i = 1; i <= n; i++)
	{
		Sparse_Table_f[i][0] = arr[i];
	}
	for (int j = 1; j <= log(n) / log(2); j++)
	{

		for (int i = 1; i <= n - (1 << j) + 1; i++)
		{ // 维护静态区间最大值
			Sparse_Table_f[i][j] = std::max(Sparse_Table_f[i][j - 1], Sparse_Table_f[i + (1 << (j - 1))][j - 1]);
		}
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;
		if (l == r) {
			std::cout << 0 << '\n';
		} else {
			std::cout << std::max(0ll, query(l, r - 1) + pre[l - 1]) << '\n';
		}
		
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}