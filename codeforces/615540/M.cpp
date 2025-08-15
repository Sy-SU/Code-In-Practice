#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::map<char, int> pos;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		std::cin >> pos[ch];
	}

	std::string str;
	std::cin >> str;

	i64 ans = 0;
	int now = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		int to = pos[str[i]];

		// now -> to

		int a = now, b = to;
		if (a > b) {
			std::swap(a, b);
		}

		int cost = std::min((b - a) * 10, 10 * (1000 - b) + a * 10 + 1);
		ans += cost;

		now = to;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}