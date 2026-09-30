#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.size();

	for (int i = 0; i < n; i += 2) {
		if (i == n - 1) {
			continue;
		}
		std::swap(s[i], s[i + 1]);
	}

	std::cout << s << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}