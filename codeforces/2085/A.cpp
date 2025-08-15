#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	if (k == 0) {
		std::string t = str;
		std::reverse(t.begin(), t.end());
		
		std::cout << (str < t ? "YES" : "NO") << '\n';
		return;
	}

	bool isok = 0;
	for (int i = 1; i < n; i++) {
		if (str[i] != str[0]) {
			isok = 1;
			break;
		}
	}
	if (isok == 0) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';
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