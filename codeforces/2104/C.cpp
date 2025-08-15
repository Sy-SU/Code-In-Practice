#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	std::vector<int> a, b;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'A') {
			a.push_back(i + 1);
		} else {
			b.push_back(i + 1);
		}
	}

	for (const auto &cardA : a) {
		bool isok = 1;
		for (const auto &cardB : b) {
			if (cardB == 1) {
				if (cardA == n) {
					isok = 0;
				}
			} else if (cardB == n) {
				if (cardA != 1) {
					isok = 0;
				}
			} else {
				if (cardA < cardB) {
					isok = 0;
				}
			}
		}
		if (isok) {
			std::cout << "Alice" << '\n';
			return;
		}
	}
	std::cout << "Bob" << '\n';
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