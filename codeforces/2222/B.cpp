#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1), x(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> x[i];
	}

	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= m; i++) {
		if (x[i] % 2) {
			cnt1++;
		} else {
			cnt0++;
		}
	}

	i64 sum = 0;

	std::vector<i64> v0, v1;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			v1.push_back(a[i]);
		} else {
			v0.push_back(a[i]);
		}
		sum += a[i];
	}

	std::sort(v0.begin(), v0.end(), std::greater<i64>());
	std::sort(v1.begin(), v1.end(), std::greater<i64>());

	for (int i = 0; i < std::min((int)v0.size(), cnt0); i++) {
		if (v0[i] < 0 && i) {
			break;
		}
		sum -= v0[i];
	}
	for (int i = 0; i < std::min((int)v1.size(), cnt1); i++) {
		if (v1[i] < 0 && i) {
			break;
		}
		sum -= v1[i];
	}
	std::cout << sum << '\n';
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