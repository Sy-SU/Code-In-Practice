#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int cnt = 0;
	std::stack<char> stk;

	for (const auto &ch : str) {
		if (ch == '(') {
			stk.push('(');
		} else {
			stk.pop();
		}

		cnt += stk.empty();
	}

	std::cout << (cnt >= 2 ? "YES" : "NO") << '\n';
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