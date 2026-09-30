#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<int, std::stack<int>> stk;
	for (int i = 1; i <= n; i++) {
		stk[a[i]].push(i);
	}

	i64 ans = 0, sum = 0;

	std::map<int, int> vis;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (!vis[a[i]]) {
			cnt++;
			vis[a[i]] = 1;
		}
		sum += cnt;
	}

	for (int i = n; i >= 1; i--) {
		ans += (n - i + 1) * sum;

		int pre = 0;
		stk[a[i]].pop();
		if (!stk[a[i]].empty()) {
			pre = stk[a[i]].top();
		}

		sum -= i - pre;
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