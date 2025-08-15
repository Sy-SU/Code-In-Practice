#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, s, t;
	std::cin >> n >> s >> t;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	if (s > t) {
		std::swap(s, t);
	}
	if (s == t) {
		std::cout << "Yes" << '\n';
		return;
	}

	if (s <= n && n + 1 <= t) {
		if (a[s] != t) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
		return;
	}

	if (t <= n) {
		// s t 都在小
		for (int i = n + 1; i <= 2 * n; i++) {
			if (a[s] != i && a[t] != i) {
				std::cout << "Yes" << '\n';
				return;
			}
		}
		std::cout << "No" << '\n';
		return;
	}

	if (s >= n + 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] != s && a[i] != t) {
				std::cout << "Yes" << '\n';
				return;
			}
		}
		std::cout << "No" << '\n';
		return;
	}

	assert(0);
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