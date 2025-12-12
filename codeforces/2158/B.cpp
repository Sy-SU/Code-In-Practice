#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> cnt(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		cnt[b[i]]++;
	}

	int ans = 0, lena = 0, lenb = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (cnt[i] == 0) {
			continue;
		}
		if (cnt[i] % 2) {
			lena++;
			ans++;
		} else {
			lena++, lenb++;
			ans += 2;
		}
	}

	if (lena == lenb) {
		if (lena % 2 != n % 2) {
			ans -= 2;
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