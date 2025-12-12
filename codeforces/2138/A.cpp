#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int k;
	i64 x;
	std::cin >> k >> x;

	i64 ini = 1;
	for (int i = 1; i <= k; i++) {
		ini *= 2;
	}

	// ini ini
	// x, 2 * ini - x

	std::vector<int> o;
	while (x != ini) {
		if (x > ini) {
			x = (x - ini) * 2;
			o.push_back(2);
		} else {
			x = x * 2;
			o.push_back(1);
		}
	}

	std::reverse(o.begin(), o.end());

	std::cout << o.size() << '\n';
	for (auto op : o) {
		std::cout << op << " ";
	}
	std::cout << '\n';
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