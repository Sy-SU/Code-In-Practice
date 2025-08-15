#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<i64> pre(n + 2), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	i64 costk = 0;
	for (int i = 1; i <= n; i++) {
		i64 x = (pre[n] - (n - i) * (k + 1)) / n;
		if (pre[n] < (n - i) * (k + 1)) {
			continue;
		}
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