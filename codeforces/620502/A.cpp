#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	std::map<char, int> cnt;
	for (auto ch : str) {
		cnt[ch]++;
	}

	int odd = 0;
	for (auto [ch, c] : cnt) {
		odd += c % 2;
	}

	std::cout << (odd >= 2 ? "NO" : "YES") << '\n';
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