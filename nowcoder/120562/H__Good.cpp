#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	auto f = [&](int l, int r) -> i64 {
		std::map<int, int> vis;
		i64 cnt = 0, res = 0;
		for (int i = l; i <= r; i++) {
			if (!vis[a[i]]) {
				cnt++;
				vis[a[i]] = 1;
			}
			res += cnt;
		}
		return res;
	};

	i64 ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			ans += f(l, r);
		}
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