#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int cnt1 = 0, cnt0 = 0;
	for (auto ch : s) {
		cnt1 += ch == '1';
		cnt0 += ch == '0';
	}
	if (cnt1 % 2 && cnt0 % 2 == 0) {
		std::cout << -1 << "\n";
		return;
	}

	if (cnt1 % 2 == 0) {
		std::cout << cnt1 << '\n';
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				std::cout << i + 1 << " ";
			}
		}
		std::cout << '\n';
	} else {
		std::cout << cnt0 << '\n';
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				std::cout << i + 1 << " ";
			}
		}
		std::cout << '\n';
	}
	
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