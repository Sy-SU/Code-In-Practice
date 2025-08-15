#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n + 1, 0), pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;
		int need = 0;
		for (int k = l; k < r; k++) {
			need = std::max(a[k + 1] - pre[k] + pre[l - 1], need);
		}
		std::cout << need << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}