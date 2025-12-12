#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int l[N], r[N];
i64 a[N];

void solve() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		l[i] = (i + n - 1) % n, r[i] = (i + 1) % n;
	}

	i64 cost = 0;
	std::vector<std::pair<i64, int>> inv;
	for (int i = 0; i < n; i++) {
		inv.push_back({a[i], i});
	}
	std::sort(inv.begin(), inv.end());

	for (int rd = 0; rd < n - 1; rd++) {
		auto [ai, i] = inv[rd];
		int left = l[i], right = r[i];

		if (a[left] < a[right]) {
			cost += a[left];
		} else {
			cost += a[right];
		}

		r[left] = right, l[right] = left;
	}
	std::cout << cost << '\n';
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