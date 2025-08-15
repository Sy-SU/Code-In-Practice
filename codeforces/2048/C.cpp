#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string s;
	std::cin >> s;

	s = "0" + s;

	int n = s.length() - 1;

	std::vector<std::string> vec;
	std::string tmp = "";

	int firstInd = -1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			firstInd = i;
			break;
		}
	}
	if (firstInd == -1) {
		std::cout << 1 << " " << n << " " << 1 <<  " " << 1 << '\n';
		return;
	}

	std::string max(n + 1, '0');
	int l = 1, r = 1;
	for (int i = 1; i < firstInd; i++) {
		// firstInd -> n
		// i -> n - firstInd + i
		std::string sbs = s.substr(i, n - firstInd + 1);
		int sl = i, sr = sl + (n - firstInd + 1) - 1;
		// std::cerr << "substr : " << sbs << '\n';
		std::string add(firstInd, '0');
		add = add + sbs;
		// std::cerr << add << " " << s << '\n';
		std::string tmpans(n + 1, '0');
		for (int j = 1; j <= n; j++) {
			if (add[j] != s[j]) {
				tmpans[j] = '1';
			}
		}
		// std::cerr << tmpans << '\n';

		bool isLarge = 0;
		for (int j = 1; j <= n; j++) {
			if (tmpans[j] > max[j]) {
				max = tmpans;
				l = sl, r = sr;
				break;
			} else if (tmpans[j] < max[j]) {
				break;
			}
		}
	}
	std::cout << 1 << " " << n << " " << l << " " << r << '\n';
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