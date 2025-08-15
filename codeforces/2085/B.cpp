#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<std::pair<int, int>> o;
	int cnt = 0;
	for (int i = 1; i + 1 <= n; i += 2) {
		if (b[i] > 0 && b[i + 1] > 0) {

		} else {
			o.push_back({i - cnt, i + 1 - cnt});
			cnt++;
		}
	}
	if (n % 2 == 1 && b[n] == 0) {
		o.push_back({n - 1 - cnt, n - cnt});
		cnt++;
	}

	o.push_back({1, n - cnt});

	std::cout << o.size() << '\n';
	for (const auto &[l, r] : o) {
		std::cout << l << " " << r << '\n';
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