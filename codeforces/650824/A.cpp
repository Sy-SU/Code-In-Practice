#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 k;
	int n;
	std::cin >> k >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int now = 1;
	i64 sum = a[now], cnt = k - 1;
	while (cnt > 0) {
		if (now < n && sum >= a[now + 1]) {
			sum += a[now + 1];
			now++, cnt--;
		} else {
			if (now == n) {
				sum += cnt * 1ll * a[now];
				cnt = 0; 
			} else {
				i64 need = std::min(cnt, (a[now + 1] - sum + a[now] - 1) / a[now]);

				sum += need * 1ll * a[now];
				cnt -= need;
			}
		}
	}
	std::cout << sum << '\n';
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