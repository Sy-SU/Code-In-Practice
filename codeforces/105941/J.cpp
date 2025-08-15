#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void solve() {
	std::string str;
	std::cin >> str;

	int n = str.size();

	int ans = 0;
	for (int sh = 0; sh < 26; sh++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int d = str[i] - 'A';
			sum += holes_cnt[(d + sh) % 26];
		}
		ans = std::max(ans, sum);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}