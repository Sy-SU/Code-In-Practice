#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 7;

int calc(std::string str) {
	int cnt = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		str[i] = (str[i] == '1' ? '0' : '1');

		bool isok = 1;
		int cnt01 = 0, cnt10 = 0;
		for (int j = 0; j + 1 < (int)str.size(); j++) {
			if (str[j] == '0' && str[j + 1] == '1') {
				cnt01++;
			}
			if (str[j] == '1' && str[j + 1] == '0') {
				cnt10++;
			}
		}

		cnt += cnt01 == cnt10;
		str[i] = (str[i] == '1' ? '0' : '1');
	}

	return cnt;
}

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int num = 0;
	for (int i = 0; i < n; i++) {
		num += str[i] == '?';
	}

	i64 ans = 0;
	for (int e = 0; e < (1 << num); e++) {
		int ne = e;
		std::string nstr = str;

		for (int i = 0; i < n; i++) {
			if (nstr[i] == '?') {
				nstr[i] = '0' + ne % 2;
				ne /= 2;
			}
		}

		ans = (ans + calc(nstr)) % mod;
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