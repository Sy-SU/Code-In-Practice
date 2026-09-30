#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string s;
	std::cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += s[i] == 'B';
	}

	if (cnt == 0) {
		while (q--) {
			int x;
			std::cin >> x;

			std::cout << x << '\n';
		}
		return;
	}

	auto sta = s;
	for (int i = 1; i <= 32; i++) {
		sta += s;
	}

	while (q--) {
		int x;
		std::cin >> x;

		int sz = sta.size();

		for (int i = 0; i < sz; i++) {
			if (sta[i] == 'A') {
				x--;
			} else {
				x /= 2;
			}

			if (x == 0) {
				std::cout << i + 1 << '\n';
				break;
			}
		}
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