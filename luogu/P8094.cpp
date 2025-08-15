#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> h(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}

	i64 ans = 0;
	std::stack<int> s;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && h[s.top()] < h[i]) {
			ans += i - s.top() + 1;
			s.pop();
		}

		if (!s.empty()) {
			ans += i - s.top() + 1;
		}

		s.push(i);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}