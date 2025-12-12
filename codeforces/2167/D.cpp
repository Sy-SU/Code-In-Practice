#include <bits/stdc++.h>

using i64 = long long;

constexpr int MAXN = 3e6 + 10;

bool Num[MAXN];
int Prime[MAXN];

void Euler_Select(int n) {
	Num[1] = Num[0] = 1;
	int pi = 0;
	for (int i = 2; i <= n; i++) {
		if (!Num[i]) {
			Prime[++pi] = i;
		}
		for (int pj = 1; Prime[pj] * i <= n; pj++) {
			Num[Prime[pj] * i] = 1;
			if (i % Prime[pj] == 0) {
				break;
			}
		}
	}
	// std::cerr << pi << '\n'; 216816
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 g = 0;
	for (int i = 1; i <= n; i++) {
		g = std::gcd(a[i], g);
	}

	for (int x = 1; x <= 200; x++) {
		if (g % Prime[x]) {
			std::cout << Prime[x] << "\n";
			return;
		}
	}

	std::cout << -1 << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Euler_Select(3000000);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}