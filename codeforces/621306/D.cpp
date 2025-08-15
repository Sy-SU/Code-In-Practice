#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int f[N];

void solve() {
	int n, k;
	std::cin >> n >> k;

	// f1 f2 
	if (k >= 29) {
		std::cout << 0 << '\n';
		return;
	}

	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	f[1] = 0, f[2] = 1;
	for (int i = 3; i <= 29; i++) {
		f[i] = f[i - 1] + f[i - 2];
		// std::cerr << i << " " << f[i] << '\n';
	}


	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}