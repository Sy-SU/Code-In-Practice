#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1, 0), b(m + 1, 0);
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		cnt1 += (a[i] == 1);
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	i64 sum = 0;
	int ptr = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 2) {
			ptr = i;
			break;
		}
	}
	int boom = ptr - 1;
	for (int i = 1; i <= m; i++) {
		sum += std::max(0ll, b[i] - boom);
		boom++;
		while (ptr <= n && a[ptr] - 1 <= boom) {
			ptr++;
			boom++;
		}
	}
	if (sum <= n - std::max(0, cnt1 - 1)) {
		std::cout << "Yes" << '\n';
	} else {
		std::cout << "No" << '\n';
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