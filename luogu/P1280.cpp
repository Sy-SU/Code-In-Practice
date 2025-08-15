#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> pre(n + 1);
	for (int i = 1; i <= k; i++) {
		int p, t;
		std::cin >> p >> t;
		t += p - 1;
		pre[t].push_back(p);
	}
	
	std::vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}