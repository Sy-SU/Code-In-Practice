#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

i64 pw[N];

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> pre(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> pre[i];
	}

	pre[0] = n + 1;
	i64 ans = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[i] > pre[i - 1]) {
			std::cout << 0 << '\n';
			return;
		} else if (pre[i] == pre[i - 1]) {
			ans = (ans * (n - pre[i] - i + 2)) % mod;
			// std::cerr << n - pre[i] - i + 1 << '\n';
		} else {
			cnt++;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		pw[i] = (pw[i - 1] * i) % mod;
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}