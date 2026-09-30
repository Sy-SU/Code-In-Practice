#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::string> s(k + 1);
	for (int i = 1; i <= k; i++) {
		std::cin >> s[i];
	}

	std::vector<std::set<char>> chset(n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			chset[i].insert(s[j][i]);
		}
	}

	for (int len = 1; len <= n; len++) {
		if (n % len) {
			continue;
		}

		int step = n / len;
		// 0, len * 1, ... len * (step - 1)
		// len * (i - 1) ~ len * (i - 1) + len - 1

		bool isok = 1;
		std::string ans;

		for (int bi = 0; bi < len; bi++) {
			std::set<char> ok;
			for (char ch = 'a'; ch <= 'z'; ch++) {
				ok.insert(ch);
			}
			// std::cerr << bi << "\n";
			for (int i = 0; i < step; i++) {
				// len * (i - 1) + bi
				// std::set<char> t;
				std::set<char> tmp;
				for (auto ch : ok) {
					if (chset[len * i + bi].find(ch) != chset[len * i + bi].end()) {
						tmp.insert(ch);
					}
				}
				ok = tmp;
			}
			if (ok.empty()) {
				isok = 0;
			} else {
				ans += *ok.begin();
			}
		}

		if (isok) {
			for (int i = 0; i < step; i++) {
				std::cout << ans;
			}
			std::cout << '\n';
			break;
		}
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