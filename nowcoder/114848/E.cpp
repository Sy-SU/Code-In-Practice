#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), v2i(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		v2i[a[i]] = i;
	}

	int l = n + 1, r = 0;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		l = std::min(l, v2i[i]), r = std::max(r, v2i[i]);
		ans += l * 1ll * (n + 1 - r);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}