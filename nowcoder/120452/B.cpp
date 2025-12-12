#include <bits/stdc++.h>

using i64 = long long;

struct Sieve {
    int n;
    std::vector<int> primes, minp;

    Sieve(int n_max = 0) {
        n = n_max;

        int pn = n / std::log(n);
        primes.reserve(pn);
        minp.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            if (!minp[i]) {
                minp[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                i64 v = i * 1ll * p;
                if (v > n) {
                    break;
                }
                minp[v] = p;
                if (p == minp[i]) {
                    break;
                }
            }
        }
    }

    bool is_prime(int x) const {
        if (x < 2 || x > n) {
            return 0;
        }
        return minp[x] == x;
    }

    std::vector<std::pair<int,int>> factorize(int x) const {
        std::vector<std::pair<int,int>> res;
        while (x > 1) {
            int p = minp[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            res.push_back({p, c});
        }
        return res;
    }
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> vis(n + 1);

	Sieve sieve(n);
	for (int i = 2; i <= n; i++) {
		if (sieve.is_prime(i) == 0) {
			for (int k = 1; k * i <= n; k++) {
				vis[k * i]++;
			}
		}
	}

	std::vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cerr << i << " " << vis[i] << '\n';
		ans[vis[i]]++;
	}
    
	while (m--) {
		int x;
        std::cin >> x;
		std::cout << ans[x] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}