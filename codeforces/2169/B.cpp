#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.size();
	s = " " + s + " ";

	std::vector<int> t(n + 2, 1e9);
	t[0] = t[n + 1] = 0;

	int l = n + 1, r = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != '<') {
			l = i;
			break;
		}
	}
	for (int i = n; i >= 1; i--) {
		if (s[i] != '>') {
			r = i;
			break;
		}
	}

	if (r - l + 1 >= 2) {
		std::cout << -1 << '\n';
		return;
	}

	std::cout << r - l + std::max(l, n + 1 - r) << '\n';
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