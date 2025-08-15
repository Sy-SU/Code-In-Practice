#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string a, b;
	std::cin >> a >> b;

	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cnt0 += (a[i] == '0'), cnt1 += (b[i] == '0');
		} else {
			cnt1 += (a[i] == '0'), cnt0 += (b[i] == '0');
		}
	}

	if (cnt0 >= (n + 1) / 2 && cnt1 >= n / 2) {
		std::cout << "YES" << '\n';
	} else {
		std::cout << "NO" << '\n';
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