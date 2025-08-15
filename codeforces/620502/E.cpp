#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> v(n + 1), a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<i64> preb(n + 1);
	for (int i = 1; i <= n; i++) {
		preb[i] = preb[i - 1] + b[i];
	}

	std::vector<i64> drink(n + 1), del_cnt(n + 1);

	for (int i = 1; i <= n; i++) {

		int lo = i, hi = n, ans = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (preb[mid] - preb[i - 1] >= a[i]) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		
		// i ~ ans - 1  ans

		i64 sum = preb[ans - 1] - preb[i - 1];
		// std::cerr << i << " " << ans << '\n';
		// a[i] - sum
		assert(a[i] >= sum);
		// add(i, ans - 1, 1)
		del_cnt[i] += v[i], del_cnt[ans] -= v[i];
		drink[ans] += std::min(b[ans], a[i] - sum) * v[i];
	}

	std::vector<i64> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[i] = del_cnt[i] + cnt[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		drink[i] += cnt[i] * b[i];
	}

	for (int i = 1; i <= n; i++) {
		std::cout << drink[i] << " \n"[i == n];
	}
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