#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string X;
	std::cin >> X;

	X = " " + X;

	std::vector<char> T(n + 1);
	for (int i = 1; i <= n; i++) {
		T[i] = (i % 2 ? 'a' : 'b');
	}

	int s = 1 << n;
	for (int _s = 0; _s < s; _s++) {
		int nw = _s;
		std::string Y = " ";
		int l = 1, r = n;
		for (int i = 1; i <= n; i++) {
			if (nw % 2) {
				Y += T[l++];
			} else {
				Y += T[r--];
			}
			nw /= 2;
		}

		// std::cerr << Y << '\n';

		bool isok = 1;
		for (int i = 1; i <= n; i++) {
			if (X[i] != '?' && X[i] != Y[i]) {
				isok = 0;
			}
		}
		if (isok) {
			std::cout << "YES" << '\n';
			return;
		}
	}
	std::cout << "NO" << '\n';
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