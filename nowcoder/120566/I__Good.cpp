#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i + 1;
	}

	bool is = 0;

	do {
		bool isok = 1;
		for (int i = 2; i < n; i++) {
			if (std::gcd(p[i - 2], p[i - 1]) == 1 && std::gcd(p[i - 2], p[i]) == 1 && std::gcd(p[i - 1], p[i]) == 1) {
				isok = 0;
			}
		}
		if (isok) {
			is = 1;
			for (int i = 0; i < n; i++) {
				std::cout << p[i] << " \n"[i == n - 1];
			}
			return;
		}
	} while (std::next_permutation(p.begin() + 1, p.end()));

	if (is == 0) {
		std::cout << -1 << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}