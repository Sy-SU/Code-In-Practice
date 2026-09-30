#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int now = 0;
	for (auto ch : s) {
		int c = ch - '0';

		if (c == 0) {
			now = 3 - now;
		} else if (c == 1) {
			if (now == 1) {now = 3;}
			else if (now == 3) {now = 1;}
		} else if (c == 2) {
			if (now == 0) {now = 1;}
			else if (now == 1) {now = 0;}
			else if (now == 2) {now = 3;}
			else if (now == 3) {now = 2;}
		} else if (c == 3) {
			if (now == 0) {now = 2;}
			else if (now == 2) {now = 0;}
		} else if (c == 4) {
			now = (now + 1) % 4;
		} else if (c == 5) {
			now = (now + 3) % 4;
		}

		std::cout << now;
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}