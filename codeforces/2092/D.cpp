#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::map<char, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}

	std::vector<int> op;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] != s[i + 1]) {
			for (int c = 0; c < 2 * cnt[s[i + 1]]; c++) {
				op.push_back(i + c);
			}
			for (int c = 0; c < 2 * cnt[s[i]]; c++) {
				op.push_back(i + 2 * cnt[s[i + 1]]);
			}

			char tar = '0';
			std::string tmp = "LIT";
			for (int x = 0; x < 3; x++) {
				if (tmp[x] != s[i] && tmp[x] != s[i + 1]) {
					tar = tmp[x];
					break;
				}
			}
			for (int c = 0; c < 2 * cnt[tar]; c++) {
				op.push_back(i + c);
			}

			std::cout << 2 * n << '\n';
			for (const auto &num : op) {
				std::cout << num + 1 << '\n';
			}
			return;
		}
	}
	std::cout << -1 << '\n';
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