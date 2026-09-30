#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, l;
	std::cin >> n >> m >> l;

	std::vector<i64> x(n + 1), y(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i];
	}
	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + x[i];
		// std::cerr << b[i] << " \n"[i == n];
	}

	for (int i = 1; i <= m; i++) {
		std::cin >> y[i];
	}

	auto check = [&](i64 x) -> bool {
		// std::cerr << x << " " << x + l << '\n';
		int lo = 1, hi = n, left = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (b[mid] <= x) {
				lo = mid + 1;
				left = mid;
			} else {
				hi = mid - 1;
			}
		}
		lo = 1, hi = n;
		int right = n + 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (b[mid] >= x + l) {
				hi = mid - 1;
				right = mid;
			} else {
				lo = mid + 1;
			}
		}
		return right - left >= 2;
	};

	i64 sta = 0; // sta ~ sta + l
	bool ans = 0;
	ans |= check(sta);
	for (int i = 1; i <= m; i++) {
		sta += y[i];
		ans |= check(sta);
	}
	std::cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}