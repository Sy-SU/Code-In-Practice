#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5

inline int lowbit(int x) {
    return x & (-x);
}

void solve() {
	int n;
	std::cin >> n;

	std::cout << (int)std::log2(n) + 1 << '\n';
	for (int i = 1; i <= n; i++) {
		auto ans = [&](int x) -> int {
			int res = 1;
			while (!(x & 1)) {
				x >>= 1;
				res++;
			}
			return res;
		};
		std::cout << ans(i) << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}