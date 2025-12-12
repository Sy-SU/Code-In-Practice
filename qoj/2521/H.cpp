#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> lst(n + 2);
	lst[n + 1] = 1e18;
	for (int i = n; i >= 1; i--) {
		lst[i] = std::min(lst[i + 1] - 1, a[i]);
		if (lst[i] < i) {
			std::cout << -1 << '\n';
			return;
		}
	}

	// lst[i] 表示 第 i 个最晚在 lst[i] 轮

	i64 ans = 0, need = 0, now = 0;
	for (int i = 1; i <= n; i++) {
		// a[i]
		// lst[i + 1] - 1
		
		i64 x = std::min({need, a[i] - now - 1, lst[i + 1] - 1 - now - 1});
		// std::cerr << need << " " << a[i] - now - 1 << " " << lst[i + 1] - 1 - now << '\n';
		now += x, ans += x, need -= x;
		now++;
		ans++;
		need += a[i] - now;
		// std::cerr << need << " " << now << '\n';
	}
	ans += need;
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