#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string s;
	std::cin >> s;

	s = " " + s;
	for (int i = 1; i <= n; i += 2) {
		s[i] = '1' - s[i] + '0';
	}

	std::vector<int> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + (s[i] != s[i - 1]);
	}

	while (q--) {
		int l, r, k;
		std::cin >> l >> r >> k;

		int rev = pre[r] - pre[l], cnt = 1e9;
		if (s[l] == s[r]) {
			cnt = rev / 2;
		} else {
			cnt = (rev + 1) / 2;
		}

		std::cout << (k >= cnt ? "YES" : "NO") << "\n";
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