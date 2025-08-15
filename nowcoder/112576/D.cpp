#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> l(n + 1), r(n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		if (l[a[i]] == 0) {
			l[a[i]] = i;
		} else {
			r[a[i]] = i;
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += r[i] - l[i] - 1;
	}

	ans += std::max(0, 2 * (*std::max_element(l.begin() + 1, l.end()) - *std::min_element(r.begin() + 1, r.end())));
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}