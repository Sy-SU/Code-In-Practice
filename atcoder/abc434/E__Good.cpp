#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<i64, i64>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 x, r;
		std::cin >> x >> r;

		vec[i] = {x - r, x + r};
	}

	int sta = (1 << n);
	int ans = 0;
	for (int s = 0; s < sta; s++) {
		int _s = s;
		std::set<i64> st;
		for (int i = 1; i <= n; i++) {
			if (_s % 2) {
				st.insert(vec[i].first);
			} else {
				st.insert(vec[i].second);
			}
			_s /= 2;
		}
		ans = std::max(ans, (int)st.size());
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}