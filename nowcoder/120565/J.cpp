#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a[3][3];

	std::set<int> s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> a[i][j];
			s.insert(a[i][j]);
		}
	}

	if (s.size() != 9) {
		std::cout << "No" << '\n';
		return;
	}

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += a[i][j];
		}
		if (sum != 15) {
			std::cout << "No" << '\n';
			return;
		}
	}

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += a[j][i];
		}
		if (sum != 15) {
			std::cout << "No" << '\n';
			return;
		}
	}

	if (a[0][0] + a[1][1] + a[2][2] != 15) {
		std::cout << "No" << '\n';
		return;
	}
	if (a[0][2] + a[1][1] + a[2][0] != 15) {
		std::cout << "No" << '\n';
		return;
	}

	std::cout << "Yes" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}