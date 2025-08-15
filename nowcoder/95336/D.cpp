#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string a, b;
	std::cin >> a >> b;

	if (n < m) {
		std::swap(a, b);
		std::swap(n, m);
	}

	std::vector<int> cnta(30, 0), cntb(30, 0);

	for (int i = 0; i < n; i++) {
		cnta[a[i] - 'a']++;
	}
	for (int i = 0; i < m; i++) {
		cntb[b[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		int min = std::min(cnta[i], cntb[i]);
		cnta[i] -= min, cntb[i] -= min;
	}

	int sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += cntb[i];
	}

	int p = 0;
	for (int i = 0; i < 26; i++) {
		p += cnta[i] / 2 * 2;
	}
	if (p + 1 >= n - m) {
		std::cout << sum << '\n';
	} else {
		std::cout << sum + (n - m - p) / 2 << '\n';
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