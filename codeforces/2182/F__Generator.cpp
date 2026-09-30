#include<bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
	return rnd() % (r - l + 1) + l;
}

i64 rngll(i64 l, i64 r) { // [l, r]
	return l + (i64)(rnd() % (unsigned long long)(r - l + 1));
}

void reindeer_case(int n, int m) {
	// n, m in [1, 500]
	std::cout << n << " " << m << "\n";

	// multiset of exponents 0..60 (counts)
	std::vector<int> cnt(61, 0);

	// initial c_i
	for (int i = 0; i < n; i++) {
		int c = rng(0, 60);
		cnt[c]++;
		std::cout << c << " \n"[i == n - 1];
	}

	// queries
	for (int qi = 0; qi < m; qi++) {
		int op = rng(1, 3);

		// If no element exists, we must avoid delete.
		int tot = 0;
		for (int v : cnt) tot += v;

		if (tot == 0) op = 1; // force add if empty

		if (op == 2) {
			// choose an x with cnt[x] > 0
			int x;
			do {
				x = rng(0, 60);
			} while (cnt[x] == 0);

			std::cout << 2 << " " << x << "\n";
			cnt[x]--;
		} else if (op == 1) {
			int x = rng(0, 60);
			std::cout << 1 << " " << x << "\n";
			cnt[x]++;
		} else {
			// query type 3
			// generate x in [1, 1e18]
			// mix small + large to cover edge cases
			i64 x;
			int mode = rng(0, 4);
			if (mode == 0) x = rngll(1, 100);                 // tiny
			else if (mode == 1) x = rngll(1, (i64)1e6);       // small
			else if (mode == 2) x = rngll((i64)1e12, (i64)1e18); // huge
			else x = rngll(1, (i64)1e18);                     // uniform-ish

			std::cout << 3 << " " << x << "\n";
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = rng(1, 10);
	int m = rng(1, 500);

	reindeer_case(n, m);

	return 0;
}
