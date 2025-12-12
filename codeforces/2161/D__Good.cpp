#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int ans = 0;

	int sit = (1 << n);
	for (int s = 0; s < sit; s++) {
		std::vector<int> now;
		int _s = s;
		for (int i = 1; i <= n; i++) {
			if (_s % 2) {
				now.push_back(a[i]);
			} 
			_s /= 2;
		}

		bool isok = 1;
		int sz = now.size();
		for (int i = 0; i < sz; i++) {
			for (int j = i + 1; j < sz; j++) {
				if (now[j] == now[i] + 1) {
					isok = 0;
				}
			}
		}
		if (isok) {
			ans = std::max(ans, sz);
		}
	}

	std::cout << n - ans << '\n';
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