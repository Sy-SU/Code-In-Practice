#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	std::map<char, int> cnt;

	for (int i = 0; i < n; i++) {
		cnt[str[i]]++;
	}

	int ans = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		ans += (cnt[ch] >= (ch - 'A' + 1));
	}
	std::cout << ans << '\n';
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