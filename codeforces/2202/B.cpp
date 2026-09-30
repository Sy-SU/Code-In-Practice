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

	char l = T[1], r = T[n];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (X[i] == '?') {
			if (l == r) {
				if (l == 'x') {
					l = 'a', r = 'b';
				} else {
					l = 'a' + 'b' - l;
				}
			} else {
				l = 'x', r = 'x';
			}
		} else {
			if (l == r && l == 'x') {
				l = 'a', r = 'b';
			} else {
				if (l == r) {
					if (X[i] != l) {
						std::cout << "NO" << '\n';
						return;
					} else {
						l = 'a' + 'b' - l;
					}
				} else {
					if (X[i] == l) {
						l = 'a' + 'b' - l;
					} else {
						r = 'a' + 'b' - r;
					}
				}
			}
		}
	}
	std::cout << "YES" << '\n';
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