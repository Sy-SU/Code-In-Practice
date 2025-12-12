#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	std::vector<std::pair<i64, int>> cnt;

	char lst = 'x';
	i64 c = 0;
	for (auto ch : s) {
		if (lst == ch) {
			c++;
		} else {
			cnt.push_back({c, lst - '0'});
			c = 1;
		}
		lst = ch;
	} 

	cnt.push_back({c, s.back() - '0'});

	i64 ans = 0;

	int sz = cnt.size();
	for (int i = 1; i < sz; i++) {
		if (cnt[i].second == cnt[i - 1].second + 1) {
			ans += std::min(cnt[i].first, cnt[i - 1].first);
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}