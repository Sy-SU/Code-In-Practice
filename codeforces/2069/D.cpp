#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int n = str.size();

	std::string s[2];
	for (int i = 0; i < n / 2; i++) {
		s[0].push_back(str[i]), s[1].push_back(str[n - i - 1]);
	}
	// std::cerr << s[0] << " " << s[1] << '\n';

	// 如果左右两边平衡
	std::map<char, int> __vis;
	for (auto ch : s[0]) {
		__vis[ch]++;
	}
	for (auto ch : s[1]) {
		__vis[ch]--;
	}
	bool isok = 1;
	for (auto [ch, num] : __vis) {
		if (num) {
			isok = 0;
			break;
		}
	}

	int ans = 1e9;
	if (isok) {
		// std::vector<int> tag(n + 1, 0);
		int fst = -1, lst = -2;
		for (int i = 0; i < n / 2; i++) {
			// tag[i] = (s[0][i] != s[1][i]);
			if (s[0][i] == s[1][i]) {
				continue;
			}
			if (fst == -1) {
				fst = i;
			}
			lst = i;
		}
		ans = std::min(ans, lst - fst + 1);
	} 
	// 否则只能从回文中心
	if (n % 2 == 0) {
		int fst = -1, scd = -2;
		for (int i = 0; i < n / 2; i++) {
			// tag[i] = (s[0][i] != s[1][i]);
			if (s[0][i] == s[1][i]) {
				continue;
			}
			if (fst == -1) {
				fst = i;
			} 
			scd = i;
			
			
		}
		ans = std::min(ans, (n / 2 - 1 - fst + 1) + (n / 2 - 1 - scd + 1));
	} else {
		int fst = -1, scd = n / 2;
		for (int i = 0; i < n / 2; i++) {
			// tag[i] = (s[0][i] != s[1][i]);
			if (s[0][i] == s[1][i]) {
				continue;
			}
			if (fst == -1) {
				fst = i;
			} 
			scd = i;
		
		}
		ans = std::min(ans, (n / 2 - 1 - fst + 1) + (n / 2 - 1 - scd + 1) + 1);
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