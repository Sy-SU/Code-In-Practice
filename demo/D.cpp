#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::map<std::string, int> cnt;

	std::string word;
	while (std::cin >> word) {
		for (auto &token : word) {
			if (token >= 'A' && token <= 'Z') {
				token -= 'A' - 'a';
			}
		}
		cnt[word]++;
	}

	int ans = 0;
	std::string answ;
	for (auto [w, c] : cnt) {
		if (c > ans) {
			ans = c, answ = w;
		} else if (c == ans) {
			if (w < answ) {
				answ = w;
			}
		}
	}
	std::cout << answ << " " << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}