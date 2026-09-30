#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	i64 b;
	std::cin >> n >> q >> b;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i] + 1;
	}

	while (q--) {
		i64 x;
		std::cin >> x;

		i64 ans = 0;
		i64 need = (x + b - 1) / b;
		ans += need * b;

		for (int i = n; i >= 1; i--) {
			ans += (need + a[i] - 1) / a[i] * (a[i] + 1);
			need = (need + a[i] - 1) / a[i];

			if (need == 1) {
				ans += pre[i - 1];
				break;
			}
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}