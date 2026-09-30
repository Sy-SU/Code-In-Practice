#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n);
	for (int i = 1; i <= n; i++) {
		p[i - 1] = i;
	}
	
	do {
		bool isok = 1;
		for (int i = 0; i < n - 1; i++) {
			bool ps = 0;
			for (int j = i; j < n; j++) {
				if (p[i] == (p[j] ^ (i + 1))) {
					ps = 1;
					break;
				}
			}
			if (ps == 0) {
				isok = 0;
				break;
			}
		}

		if (isok) {
			for (int i = 0; i < n; i++) {
				std::cout << p[i] << " \n"[i == n - 1];
			}
			// return;
		}
	} while (std::next_permutation(p.begin(), p.end()));

	std::cout << -1 << '\n';
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