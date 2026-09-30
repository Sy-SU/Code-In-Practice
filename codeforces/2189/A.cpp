#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, h, l;
	std::cin >> n >> h >> l;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	if (h >= l) {
		std::swap(h, l);
	}

	std::sort(a.begin() + 1, a.end());

	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= h) {
			cnt1++;
		} else if (a[i] <= l) {
			cnt2++;
		}
	}

	if (cnt1 <= cnt2) {
		std::cout << cnt1 << '\n';
	} else {
		std::cout << (cnt1 + cnt2) / 2 << '\n';
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