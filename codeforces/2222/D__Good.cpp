#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	std::vector<std::vector<int>> ansp;
	i64 ans = -1e18;

	do {
		// for (int i = 1; i <= n; i++) std::cerr << p[i] << " \n"[i == n];
		i64 sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (p[i] > p[j]) {
					for (int k = i; k < j; k++) {
						sum += a[k];
					}
				}
			}
		}

		if (sum > ans) {
			ans = sum;
			ansp.clear();
			ansp.push_back(p);
		} else if (sum == ans) {
			ansp.push_back(p);
		}
		// std::cerr << sum << " " << ans << '\n';
	} while (std::next_permutation(p.begin() + 1, p.end()));
	std::cout << "ans = " << ans << '\n';
	std::cout << "p = " << '\n';
	for (auto vp : ansp) {
		for (int i = 1; i <= n; i++) {
			std::cout << vp[i] << " \n"[i == n];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}