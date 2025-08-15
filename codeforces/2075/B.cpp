#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	if (k == 1) {
		i64 ans = 0;

		i64 tmp = 0;
		for (int i = 2; i <= n; i++) {
			tmp = std::max(tmp, a[i]);
		}
		ans = std::max(ans, a[1] + tmp);

		tmp = 0;
		for (int i = 1; i <= n - 1; i++) {
			tmp = std::max(tmp, a[i]);
		}
		ans = std::max(ans, a[n] + tmp);

		std::cout << ans << '\n';
		return;
	}
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		i64 tmp = 0, sum = a[i], cnt = 0;

		std::vector<i64> vec;
		vec.push_back(0);

		for (int j = 1; j <= i - 1; j++) {
			tmp = std::max(tmp, a[j]);
		} 
		if (tmp) {
			sum += tmp;
			cnt++;
		}
		for (int j = 1; j <= i - 1; j++) {
			if (a[j] == tmp) {
				tmp = 0;
			} else {
				vec.push_back(a[j]);
			}
 		}

		for (int j = i + 1; j <= n; j++) {
			tmp = std::max(tmp, a[j]);
		}
		if (tmp) {
			sum += tmp;
			cnt++;
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == tmp) {
				tmp = 0;
			} else {
				vec.push_back(a[j]);
			}
 		}

 		std::sort(vec.begin(), vec.end(), std::greater<i64>());
 		for (int j = 0; j < k - cnt; j++) {
 			sum += vec[j];
 		}
 		ans = std::max(ans, sum);
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