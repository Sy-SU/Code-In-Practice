#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> f(n + 2, std::vector<i64>(30));
	for (int i = 1; i <= n; i++) {
		f[i][0] = a[i];
	}
	for (int j = 1; j <= log(n) / log(2); j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}

	auto q = [&](int l, int r) -> i64 {
		int x = log(r - l + 1) / log(2);
		return std::max(f[l][x], f[r - (1 << x) + 1][x]);
	};

	std::vector<int> da(n + 2);
	for (int i = 1; i <= n; i++) {
		// left
		int lo = 1, hi = i, left = i;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (q(mid, i) == a[i]) {
				hi = mid - 1;
				left = mid;
			} else {
				lo = mid + 1;
			}
		}

		// left ~ i
		da[left]++, da[i + 1]--;

		lo = i, hi = n;
		int right = i;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (q(i, mid) == a[i]) {
				lo = mid + 1;
				right = mid;
			} else {
				hi = mid - 1;
			}
		}

		da[i]++, da[right + 1]--;
	}

	int now = 0;
	for (int i = 1; i <= n; i++) {
		now += da[i];
		std::cout << now - 1 << " \n"[i == n];
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