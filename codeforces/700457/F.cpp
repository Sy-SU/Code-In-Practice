#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	s = " " + s;

	for (int i = 1; i <= n; i++) {
		if (i >= 24) {
			int rest = 0;
			for (int j = i - 23; j <= i; j++) {
				rest += s[j] == 'T';
			}

			if (rest < 10) {
				std::cout << "No" << '\n';
				std::cout << i << '\n';
				return;
			}

			std::vector<int> v;
			int r = 0;
			for (int j = i - 23; j <= i; j++) {
				if (s[j] == 'T') {
					r++;
				} else {
					if (r) {
						v.push_back(r);
						r = 0;
					}
				}
			}
			if (r) {
				v.push_back(r);
			}

			std::sort(v.begin(), v.end(), std::greater<int>());
			if (v.size() > 2 || v[0] < 6) {
				std::cout << "No" << '\n';
				std::cout << i << '\n';
				return;
			}
		}

		if (i >= 168) {
			int rest = 0;
			for (int j = i - 167; j <= i; j++) {
				rest += s[j] == 'T';
			}

			if (rest < 77) {
				std::cout << "No" << '\n';
				std::cout << i << '\n';
				return;
			}
		}
	}

	std::cout << "Yes" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}