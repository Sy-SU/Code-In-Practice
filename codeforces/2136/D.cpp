#include <bits/stdc++.h>

using i64 = long long;

using P = std::pair<i64, i64>;

i64 ask(char d, i64 k) {
	std::cout << "? " << d << " " << k << std::endl;
	i64 ans;
	std::cin >> ans;

	return ans;
}

void solve() {
	int n;
	std::cin >> n;

	i64 maxx = 0, maxy = 0;
	i64 max_x_p_y = -1e18, max_x_d_y = -1e18;

	std::vector<P> pt(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> pt[i].first >> pt[i].second;
		maxx = std::max(maxx, pt[i].first);
		maxy = std::max(maxy, pt[i].second);
		max_x_d_y = std::max(max_x_d_y, pt[i].first - pt[i].second);
		max_x_p_y = std::max(max_x_p_y, pt[i].first + pt[i].second);
	}

	i64 res = ask('R', 1000000000);
	res = ask('R', 1000000000);
	res = ask('U', 1000000000);
	res = ask('U', 1000000000);

	i64 XpY = res + max_x_p_y - 4000000000ll;

	res = ask('D', 1000000000);
	res = ask('D', 1000000000);
	res = ask('D', 1000000000);
	res = ask('D', 1000000000);

	i64 XdY = res + max_x_d_y - 4000000000ll;
	
	i64 X = (XpY + XdY) / 2, Y = (XpY - XdY) / 2;

	std::cout << "! " << X << " " << Y << std::endl;
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