#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> vis(n + 1), A, B;
	for (int i = 1; i <= 2 * n; i++) {
		if (vis[a[i]] == 0) {
			vis[a[i]] = 1;
			A.push_back(a[i]);
		} else {
			B.push_back(a[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << A[i] << " \n"[i == n];
	}
	for (int i = 0; i < n; i++) {
		std::cout << B[i] << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}