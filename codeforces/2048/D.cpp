#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1, 0), b(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	int ak = a[1];
	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	std::vector<i64> cnt(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		int lo = 1, hi = n;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid] >= b[i]) {
				hi = mid - 1;
				ans = n - mid + 1;
			} else {
				lo = mid + 1;
			}
		}
		cnt[i] = ans;
	}

	int cntSolved = 0;
	for (int i = 1; i <= m; i++) {
		if (b[i] > ak) {
			break;
		} else {
			cntSolved++;
		}
	}

	for (int k = 1; k <= m; k++) {
		i64 sum = 0;
		i64 del = 0;

		int res = m % k;

		for (int i = cntSolved + res + 1; i <= m; i += k) {
			sum += cnt[i] + 1, del++;
		}
		sum += m / k - del;
		std::cout << sum << " ";
	}
	std::cout << '\n';
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