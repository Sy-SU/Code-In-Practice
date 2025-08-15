#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	s = " " + s + " ";

	std::vector<int> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + (s.substr(i - 1, 3) == "xjx");
	}

	while (k--) {
		int l, r;
		std::cin >> l >> r;

		std::cout << std::max(0, pre[r - 1] - pre[l]) << '\n';

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}