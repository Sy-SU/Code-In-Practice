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

	std::vector<i64> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[i] = i;
	}
	std::sort(ind.begin() + 1, ind.end(), [&](int i, int j) {
		return pre[i - 1] > pre[j - 1];
	});

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		p[ind[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
	}
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