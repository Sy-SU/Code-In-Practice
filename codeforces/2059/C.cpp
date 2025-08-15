#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}
	std::vector<int> vec;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = n; j >= 1; j--) {
			if (a[i][j] != 1) {
				break;
			}
			cnt++;
		}
		vec.push_back(cnt);
	}

	std::sort(vec.begin(), vec.end());
	int now = 0, idx = 0;
	while (idx < (int)vec.size()) {
		if (vec[idx] < now) {
			idx++;
			continue;
		}
		idx++;
		now++;
	}
	std::cout << now << '\n';
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