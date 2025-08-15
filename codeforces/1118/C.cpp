#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n * n + 1);
	for (int i = 1; i <= n * n; i++) {
		std::cin >> a[i];
	}

	std::map<int, int> cnt;
	for (int i = 1; i <= n * n; i++) {
		cnt[a[i]]++;
	}

	int f = 0, g = 0;
	for (auto [num, c] : cnt) {
		f += (c % 4 == 1), g += (c % 4 == 2);
		if (c % 4 == 3) {
			std::cout << "No" << '\n';
			return;
		}
	}

	std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1));

	if (n % 2) {
		if (f > 1) {
			std::cout << "No" << '\n';
			return;
		}
		if (g > 2) {
			std::cout << "Yes" << '\n';
			return;
		}

		
	} else {
		if (f) {
			std::cout << "No" << '\n';
			return;
		}
		if (g) {
			std::cout << "No" << "\n";
			return;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}