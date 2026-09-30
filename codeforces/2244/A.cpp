#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int max = 0, cnt = 0;
	for (auto ch : s) {
		if (ch == '#') {
			cnt++;
		} else {
			max = std::max(max, cnt);
			cnt = 0;
		}
	}

	max = std::max(max, cnt);

	std::cout << (max + 1) / 2 << '\n';
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