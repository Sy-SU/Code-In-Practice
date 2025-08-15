#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x;
	std::cin >> x;

	std::vector<int> arr(3);
	arr[0] = arr[1] = arr[2] = x;

	int cnt = 0;
	while (1) {
		std::sort(arr.begin(), arr.end());
		if (arr[2] == 0) {
			break;
		}
		cnt++;

		arr[2] = arr[1] / 2;
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