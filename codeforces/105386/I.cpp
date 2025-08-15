#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string s;
	std::cin >> s;

	int cnt = 1;
	std::vector<int> con;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cnt++;
		} else {
			con.push_back(cnt);
			cnt = 1;
		}
	}
	con.push_back(cnt);
	// for (const auto& num : con) {
	// 	std::cerr << num << " ";
	// }
	// std::cerr << '\n';
	int cnt1 = 0, cnt2 = 0;
	for (const auto& num : con) {
		cnt1 += num / 2;
	}
	if (con.size() == 1) {
		cnt2 = cnt1;
	} else {
		if (s[0] == s[(int)s.size() - 1]) {
			con[0] += con[(int)con.size() - 1];
			con[(int)con.size() - 1] = 0;
		}
		bool isok = 0;
		for (const auto& num : con) {
			cnt2 += num / 2;
			if (num % 2 == 0 && num != 0) {
				isok = 1;
			}
		}
		cnt2 -= isok;
	}
	std::cout << std::min(cnt1, cnt2) << '\n';

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