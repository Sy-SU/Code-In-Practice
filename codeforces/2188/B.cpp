#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int cnt = 0, ans = 0;
	std::vector<int> seg;
	for (auto ch : s) {
		if (ch == '1') {
			seg.push_back(cnt);
			cnt = 0, ans++;
		} else {
			cnt++;
		}
	}

	seg.push_back(cnt);
	

	// for (auto sg : seg) {
	// 	std::cerr << sg << " ";
	// }
	// std::cerr << '\n';

	if (seg.size() == 1) {
		ans += (seg[0] + 2) / 3;
	} else if (seg.size() > 1) {
		ans += (seg[0] + 1) / 3 + (seg.back() + 1) / 3;

		int sz = seg.size();
		for (int i = 1; i < sz - 1; i++) {
			ans += seg[i] / 3;
		}
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