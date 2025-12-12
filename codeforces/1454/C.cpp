#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> op(n + 1);
	std::set<int> ok;

	int sta = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != sta) {
			op[a[i]]++;
			sta = a[i];
		}
		ok.insert(a[i]);
	}

	op[a[1]]--, op[a[n]]--;

	int ans = 1e9;
	for (auto num : ok) {
		ans = std::min(ans, op[num] + 1);
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