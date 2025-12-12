#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> sta(n + 1, -1);
	for (int i = 1; i <= m; i++) {
		int x, t;
		std::cin >> t >> x;

		sta[t] = 1 - x;
	}

	sta[0] = 0;
	int lst = 0, cnt = 0;
	int min = 0, bonus = 0;

	for (int i = 1; i <= n; i++) {
		if (sta[i] == -1) {
			cnt++;
		} else {
			if (lst != sta[i]) {
				min += 1;
				bonus += cnt / 2;
			} else {
				min += 0;
				bonus += (cnt + 1) / 2;
			}

			lst = sta[i], cnt = 0;
		}
	}

	int fr = 0;
	fr += cnt;

	// std::cerr << min << " " << bonus << " " << fr << '\n';

	int t;
	std::cin >> t;

	while (t--) {
		int s;
		std::cin >> s;

		if (s < min) {
			std::cout << "No" << '\n';
			continue;
		}
		if (s <= min + fr) {
			std::cout << "Yes" << '\n';
			continue;
		}
		int jifr = fr, oufr = fr;
		if (jifr % 2 == 0) {
			jifr--;
		}
		if (oufr % 2 == 1) {
			oufr--;
		}
		// std::cerr << min << " " << bonus << " " << oufr << " " << jifr << '\n';

		if (s % 2 == min % 2) {
			if (s <= min + bonus * 2 + oufr) {
				std::cout << "Yes" << '\n';
			} else {
				std::cout << "No" << '\n';
			}
		} else {
			if (jifr == -1) {
				std::cout << "No" << '\n';
				continue;
			}
			if (s <= min + bonus * 2 + jifr) {
				std::cout << "Yes" << '\n';
			} else {
				std::cout << "No" << '\n';
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}