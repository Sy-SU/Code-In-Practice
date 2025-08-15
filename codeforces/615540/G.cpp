#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<int, int> func;
	for (int i = 1; i <= n; i++) {
		func[a[i]] = i;
	}

	int ans = 0;

	int lst = 2e9;
	for (const auto &[val, pos] : func) {
		if (pos < lst) {
			lst = pos;
			ans++;
		} else {
			lst = pos;
		}
	}
	std::cout << ans << '\n';

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}