#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		cnt += str[i] == str[n - 1];
	}

	std::cout << n - cnt << '\n';
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