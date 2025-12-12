#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> n0, n1;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2) {
			n1.push_back(a[i]);
		} else {
			n0.push_back(a[i]);
		}
	}

	std::sort(n0.begin(), n0.end(), std::greater<i64>());
	std::sort(n1.begin(), n1.end(), std::greater<i64>());

	if (n1.empty()) {
		for (int i = 1; i <= n; i++) {
			std::cout << 0 << " \n"[i == n];
		}
		return;
	}

	std::vector<i64> ans(n + 1);

	i64 sum = 0;

	sum += n1[0], ans[1] = sum;

	for (int i = 0; i < (int)n0.size(); i++) {
		sum += n0[i], ans[i + 2] = sum;
	}

	int now = 2 + (int)n0.size();
	for (int i = 1; i + 1 < (int)n1.size(); i += 2) {
		ans[now] = ans[now - 2], ans[now + 1] = ans[now - 1];
		now += 2;
	}

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
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