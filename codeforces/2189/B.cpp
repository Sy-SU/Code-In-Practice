#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	i64 a, b, c;
};

void solve() {
	int n;
	i64 x;
	std::cin >> n >> x;

	std::vector<Node> node(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 a, b, c;
		std::cin >> a >> b >> c;

		node[i] = {a, b, c};
	}

	i64 maxb = 0;
	for (int i = 1; i <= n; i++) {
		auto [a, b, c] = node[i];
		maxb += (b - 1) * a;
	}

	i64 maxadd = -1e18;
	for (int i = 1; i <= n; i++) {
		auto [a, b, c] = node[i];
		maxadd = std::max(maxadd, -c + b * a);
	}

	if (maxadd <= 0 && maxb < x) {
		std::cout << -1 << '\n';
		return;
	}

	if (maxb >= x) {
		std::cout << 0 << '\n';
		return;
	}

	i64 ans = 0;
	ans = std::max(ans, (x - maxb + maxadd - 1) / maxadd);

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