#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> q(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> q[i];
		q[i]++;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> r[i];
		r[i]++;
	}

	k++;

	std::sort(q.begin() + 1, q.end());
	std::sort(r.begin() + 1, r.end());

	int ans = 0, ptr = n;
	for (int i = 1; i <= n; i++) {
		while (ptr >= 1 && q[i] * r[ptr] > k) {
			ptr--;
		}
		if (ptr == 0) {
			break;
		}
		ans++, ptr--;
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