#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	// C 看了一下大一学弟的代码（vanadium-23）
	// 发现 C 其实很简单（好强orz）
	// C 实际上就是，把相邻的相同的数合并一下
	// 类似于 1 2 2 3 2 2 2 1 变成 1 2 3 2 1
	// 然后数有多少个峰， 就是类似于 3 5 4 或者 1 3 2 这种

	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int ptr = 0;
	std::vector<int> b(n + 2);
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[ptr]) {
			continue;
		}
		b[++ptr] = a[i];
	}

	int ans = 0;
	for (int i = 1; i <= ptr; i++) {
		ans += (b[i] > b[i - 1] && b[i] > b[i + 1]);
	}
	std::cout << ans << '\n';

	// 在 system testing，等会交
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