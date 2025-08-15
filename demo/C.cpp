#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	i64 A = 0, B = 0;

	std::vector<i64> w;
	for (int i = 1; i <= n; i++) {
		int s;
		std::cin >> s;

		std::vector<i64> a(s + 1);
		for (int i = 1; i <= s; i++) {
			std::cin >> a[i];
		}

		if (s % 2) {
			w.push_back(a[(s + 1) / 2]);
		}
		for (int i = 1; i <= s / 2; i++) {
			A += a[i], B += a[s + 1 - i];
		}
	}

	std::sort(w.begin(), w.end(), std::greater<i64>());
	i64 x = 1;
	for (auto num : w) {
		if (x) {
			A += num;
		} else {
			B += num;
		}
		x = 1 - x;
	}

	std::cout << A << " " << B << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}