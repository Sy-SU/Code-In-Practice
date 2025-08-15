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

	std::vector<i64> need;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		i64 now = 1;
		int cnt = 0;
		while (now <= 1000000000000000000ll) {
			if (((a[i] >> cnt) & 1) == 0) {
				need.push_back(now);
			} else {
				ans++;
			}
			cnt++, now *= 2;
		}
	}

	std::sort(need.begin(), need.end());
	for (const auto &nd : need) {
		if (nd > k) {
			break;
		} else {
			ans++;
			k -= nd;
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