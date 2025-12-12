#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
    std::cin >> n;
    
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(30));
    
    for (int i = 1; i <= n; i++) {
        f[i][0] = a[i];
    }
    
    for (int j = 1; j <= log(n) / log(2); j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    auto query = [&](int l, int r) -> int {
        int x = log(r - l + 1) / log(2);
        return std::abs(std::max(f[l][x], f[r - (1 << x) + 1][x]));
    };
    
    i64 ans = 0;
    for (int r = 3; r <= n; r++) {
        int lo = 2, hi = r - 1, l = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (query(mid, r - 1) < a[r]) {
                hi = mid - 1;
                l = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (l == -1) {
            continue;
        }
        for (int i = l - 1; i <= r - 2; i++) {
            if (query(i + 1, r - 1) < std::min(a[i], a[r])) {
                ans += a[i] != a[r];
            }
        }
    }
    std::cout << ans << '\n';
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