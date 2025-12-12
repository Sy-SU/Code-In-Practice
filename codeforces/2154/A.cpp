#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			continue;
		}

		bool isok = 1;
		for (int j = std::max(0, i - k + 1); j < i; j++) {
			if (str[j] == '1') {
				isok = 0;
			}
		}
		cnt += isok;
	}

	std::cout << cnt << '\n';
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