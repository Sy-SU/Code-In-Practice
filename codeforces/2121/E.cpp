#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string l, r;
	std::cin >> l >> r;

	int ans = 0, sz = l.size();
	for (int i = 0; i < sz; i++) {
		// std::cerr << l[i] << " " << r[i] << '\n';
		if (r[i] - l[i] >= 2) {
			std::cout << ans << '\n';
			return;
		}
		if (r[i] == l[i]) {
			ans += 2;
		} else {
			ans++;
			for (int j = i + 1; j < sz; j++){
				if (l[j] != '9' || r[j] != '0') {
					break;
				}
				ans++;
			}
			std::cout << ans << '\n';
			return;
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