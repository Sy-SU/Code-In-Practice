#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 10;

void solve() {
	int n, x;
	std::cin >> n >> x;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int ans = 1e9;

	std::vector<int> lst(N + 1, 0);
	lst[0] = 1;
	for (int i = 1; i <= n; i++) {
		std::vector<int> now(N + 1, 0);
		for (int j = 0; j <= N; j++) {
			if (lst[j]) {
				now[j + a[i]] = now[j] = 1;
				if (j >= x) {
					ans = std::min(ans, j);
				}
				if (j + a[i] >= x) {
					ans = std::min(ans, j + a[i]);
				}
			}
		}
		lst = now;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}