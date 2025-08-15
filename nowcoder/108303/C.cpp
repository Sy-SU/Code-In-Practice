#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 10;
constexpr int mod = 998244353;

i64 A[N], B[N], C[N];
i64 pw[N];

void solve() {
	int n;
	std::cin >> n;

	std::cout << A[n] << '\n';
} 

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 500000; i++) {
		pw[i] = (pw[i - 1] * i) % mod;
	}

	for (int i = 1; i <= 500000; i++) {
		C[i] = (i * C[i - 1] % mod + pw[i - 1]) % mod;
	}

	for (int i = 1; i <= 500000; i++) {
		B[i] = (i * B[i - 1] % mod + 2 * C[i - 1] + pw[i - 1]) % mod;
	}

	for (int i = 1; i <= 500000; i++) {
		A[i] = (i * A[i - 1] % mod + 3 * B[i - 1] + 3 * C[i - 1] + pw[i - 1]) % mod;
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}