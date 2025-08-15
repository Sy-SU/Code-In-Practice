#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int ans = 1e9;
	for (int i = 0; i < (int)str.size(); i++) {
		std::string tmpstr;
		tmpstr += str.substr(i, (int)str.size() - i);
		tmpstr += str.substr(0, i);

		int cnt = 1, tmpans = 0;
		for (int j = 1; j < (int)tmpstr.size(); j++) {
			if (tmpstr[j] == tmpstr[j - 1]) {
				cnt++;
			} else {
				tmpans += cnt / 2;
				cnt = 1;
			}
		}
		tmpans += cnt / 2;
		ans = std::min(ans, tmpans);
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