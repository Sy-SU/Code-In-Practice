#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	if (k > n / 2) {
		std::cout << -1 << '\n';
		return;
	}

	int cntr = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			cntr++;
		} else {
			if (cntr < k) {
				s[i] = 'R';
				cntr++, ans++;
			}
		}
	}

	int cntl = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'L') {
			cntl++;
		} else {
			if (cntl < k) {
				s[i] = 'L';
				cntl++, ans++;
			}
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