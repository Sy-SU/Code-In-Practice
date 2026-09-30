#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::string x;
	std::cin >> x;

	x = " " + x;

	std::vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[p[i]] = i;
	}

	int l = std::min(ind[1], ind[n]), r = std::max(ind[1], ind[n]);

	std::string s(n + 1, '0');

	auto f = [&](int l, int r) -> void {
		for (int i = l; i <= r; i++) {
			if (p[i] > std::min(p[l], p[r]) && p[i] < std::max(p[l], p[r])) {
				s[i] = '1';
			}
		}
	};

	f(1, r), f(1, l), f(l, n), f(r, n), f(l, r);

	bool isok = 1;
	for (int i = 1; i <= n; i++) {
		if (x[i] == '1' && s[i] == '0') {
			isok = 0;
		} 
	}

	if (isok == 0) {
		std::cout << -1 << '\n';
	} else {
		std::cout << 5 << '\n';
		std::cout << 1 << " " << r << '\n';
		std::cout << 1 << " " << l << '\n';
		std::cout << l << " " << n << '\n';
		std::cout << r << " " << n << '\n';
		std::cout << l << " " << r << '\n';
	}
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