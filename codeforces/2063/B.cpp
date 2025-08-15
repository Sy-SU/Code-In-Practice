#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

i64 a[N], pre[N];

void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a + 1, a + l);
	std::sort(a + l, a + r + 1);
	std::sort(a + r + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	int ptrl = 0, ptrr = r;
	i64 ans = pre[r] - pre[l - 1];
	while (1) {
		if (ptrl > l - 1 || ptrr < l - 1) {
			break;
		}
		ans = std::min(ans, pre[ptrr] - pre[l - 1] + pre[ptrl]);

		ptrl++, ptrr--;
	}

	ptrl = r, ptrr = r;
	while (1) {
		if (ptrl < l - 1 || ptrr > n) {
			break;
		}
		ans = std::min(ans, pre[ptrl] - pre[l - 1] + pre[ptrr] - pre[r]);

		ptrl--, ptrr++;
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