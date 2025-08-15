#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b = a;
	std::sort(b.begin() + 1, b.end());

	int x = b[k];

	std::vector<int> arr;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			arr.push_back(a[i]);
		}
	}

	int sz = arr.size();

	// for (int i = 0; i < sz; i++) {
	// 	std::cerr << arr[i] << " \n"[i == sz - 1];
	// }

	int l = 0, r = sz - 1, cnt = 0;
	while (l < r) {
		while (arr[l] != arr[r]) {
			if (arr[l] == x) {
				l++;
			} else if (arr[r] == x) {
				r--;
			} else {
				std::cout << "NO" << '\n';
				return;
			}
			cnt++;
		}
		l++, r--;
	}

	if (sz - cnt < k - 1) {
		std::cout << "NO" << '\n';
	} else {
		std::cout << "YES" << '\n';
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