#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> v(n + 1);
	std::vector<int> a(n + 1), b(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	i64 ans = -1e9;
	int sit = (1 << n);
	for (int s = 0; s < sit; s++) {
		int now = s;
		std::vector<int> vis(n + 1);
		i64 tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (now % 2) {
				for (int j = 1; j <= n;j++) {
					if (vis[a[j]]) {
						continue;
					}
					vis[a[j]] = 1;
					tmp += v[a[j]];
					break;
				}
			} else {
				for (int j = 1; j <= n;j++) {
					if (vis[b[j]]) {
						continue;
					}
					vis[b[j]] = 1;
					break;
				}
			}
			now /= 2;
		}
		ans = std::max(ans, tmp);
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