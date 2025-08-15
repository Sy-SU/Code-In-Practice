#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> gcd_st(n + 1, std::vector<int>(30));
	std::vector<std::vector<int>> min_st(n + 1, std::vector<int>(30, 1e9));

	for (int i = 1; i <= n; i++) {
        gcd_st[i][0] = min_st[i][0] = a[i];
    }

	for (int j = 1; j <= log(n) / log(2); j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            min_st[i][j] = std::min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1]);
        	gcd_st[i][j] = std::__gcd(gcd_st[i][j - 1], gcd_st[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto rmin = [&](int l, int r) -> int {
    	int x = log(r - l + 1) / log(2);
    	return std::min(min_st[l][x], min_st[r - (1 << x) + 1][x]);
    };

    auto rgcd = [&](int l, int r) -> int {
    	int x = log(r - l + 1) / log(2);
    	return std::__gcd(gcd_st[l][x], gcd_st[r - (1 << x) + 1][x]);
    };

    // std::cerr << rgcd(1, 1) << '\n';

    i64 ans = 0;
    for (int l = 1; l <= n; l++) { 
    	for (int r = l; r <= n; r++) {
    		if (rmin(l, r) == rgcd(l, r)) {
    			ans++;
    		}
    	}
   	}
   	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}