#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int r0, x, d, n;
	std::cin >> r0 >> x >> d >> n;

	std::string str;
	std::cin >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '2') {
			if (r0 >= x) {
				continue;
			} else {
				r0 = std::max(0, r0 - d);
				cnt++;
			}
		} else {
			r0 = std::max(0, r0 - d);
			cnt++;
		}
	}
	std::cout << cnt << '\n';
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