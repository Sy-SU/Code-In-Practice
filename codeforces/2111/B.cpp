#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int f[20];

void solve() {
	int n, m;
	std::cin >> n >> m;

	while (m--) {
		std::vector<int> arr(3);
		std::cin >> arr[0] >> arr[1] >> arr[2];

		std::sort(arr.begin(), arr.end());

		bool ans = 1;
		if (f[n] > arr[0]) {
			ans = 0;
		}
		if (f[n] + f[n - 1] > arr[2]) {
			ans = 0;
		}
		std::cout << ans;
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= 10; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}