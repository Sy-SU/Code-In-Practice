#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	std::string T = "uwawauwa";

	int cnt = 0, cntu = 0;
	for (int i = 0; i + 7 < (int)str.size(); i++) {
		bool isok = 1;
		for (int j = 0; j < 8; j++) {
			if (T[j] != str[i + j]) {
				isok = 0;
				break;
			}
		}
		if (isok) {
			cnt += cntu;
		}
		if (i && str[i - 1] == 'u') {
			cntu++;
		}
	}
	std::cout << cnt << '\n';
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