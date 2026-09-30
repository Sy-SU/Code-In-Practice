#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	auto b = a;
	std::sort(b.begin() + 1, b.end());

	std::vector<int> c;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			c.push_back(b[i]);
		}
	}

	int k = 2e9;

	for (int i = 0; i < (int)c.size(); i++) {
		k = std::min(k, std::max({c[i] - b[1], b[n] - c[i]}));
	}

	if (k > 1e9) {
		k = -1;
	}
	std::cout << k << "\n";
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