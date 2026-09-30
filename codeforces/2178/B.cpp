#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	s += 'u';

	char lst = 'u';
	int cnt = 0;
	for (auto ch : s) {
		char now = ch;
		if (lst == 'u' && ch == 'u') {
			now = 's', cnt++;
		}
		lst = now;
	}
	std::cout << cnt << "\n";
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