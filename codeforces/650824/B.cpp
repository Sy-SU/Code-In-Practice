#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		std::vector<int> t;
		int besta = a[i];
		while (a[i]) {
			t.push_back(a[i] % 10);
			a[i] /= 10;
		}

		int sz = t.size();
		for (int j = sz - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				std::swap(t[j], t[k]);

				int ta = 0, base = 1;
				for (int b = 0; b < sz; b++) {
					ta += base * t[b];
					base *= 10;
				}
				besta = std::max(besta, ta);

				std::swap(t[j], t[k]);
			}
		}

		ans += besta;
	}

	std::cout << ans << '\n';
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