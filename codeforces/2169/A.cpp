#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, a;
	std::cin >> n >> a;

	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}

	auto check = [&](int b) -> int {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (std::abs(v[i] - a) > std::abs(v[i] - b)) {
				cnt++;
			}
		}
		return cnt;
	};

	if (check(a + 1) > check(a - 1)) {
		std::cout << a + 1 << '\n';
	} else {
		std::cout << a - 1 << '\n';
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