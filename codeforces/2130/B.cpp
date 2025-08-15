#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, s;
	std::cin >> n >> s;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}

	if (sum > s) {
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << " \n"[i == n];
		}
		return;
	}

	if (sum == s) {
		std::cout << -1 << '\n';
		return;
	}

	if (sum <= s - 2) {
		std::cout << -1 << '\n';
		return;
	}

	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		cnt0 += a[i] == 0, cnt1 += a[i] == 1, cnt2 += a[i] == 2;
	}

	for (int i = 1; i <= cnt0; i++) {
		std::cout << 0 << " ";
	}
	for (int i = 1; i <= cnt2; i++) {
		std::cout << 2 << " ";
	}
	for (int i = 1; i <= cnt1; i++) {
		std::cout << 1 << " ";
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}