#include <bits/stdc++.h>

using i64 = long long;

struct Sieve {
    /*
    Sieve sieve(n); // 0-indexed primes <= n

    // 对 n 分解质因数
    auto f = sieve.factorize(n);
    std::cout << n << " = ";
    for (int i = 0; i < (int)f.size(); i++) {
        std::cout << f[i].first << "^" << f[i].second;
        if (i + 1 < (int)f.size()) std::cout << " * ";
    }
    std::cout << '\n';
    */
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

Sieve sieve(1000000);

std::vector<i64> base;

void solve() {
	int n;
	std::cin >> n;

	std::map<i64, bool> vis;
	std::map<i64, bool> numv;

	i64 pre = -1;

	std::vector<i64> b(n + 2);
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < (int)base.size(); x++) {
			if (pre == -1 || vis[std::gcd(base[x], pre)] == 0) {
				if (numv[base[x]] == 0) {
					if (pre != -1) {
						vis[std::gcd(base[x], pre)] = 1;
					}
					b[i] = b[i + 1] = base[x];
					vis[base[x]] = 1;
					numv[base[x]] = 1;
					pre = base[x];
					i++;
				} else {
					if (pre != -1) {
						vis[std::gcd(base[x], pre)] = 1;
					}
					b[i] = base[x];
					pre = base[x];
				}

				break;
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cout << b[i] << " \n"[i == n];
	// }

	std::set<i64> var;
	for (int i = 1; i <= n; i++) {
		var.insert(b[i]);
	}
	std::cerr << "n = " << n << " var = " << var.size() << '\n'; 

	std::set<i64> st;
	for (int i = 2; i <= n; i++) {
		st.insert(std::gcd(b[i - 1], b[i]));
	}

	assert(st.size() == n - 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 mul = 1;
	for (int i = 0; i < 15; i++) {
		mul *= sieve.primes[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = i + 1; j < 15; j++) {
			base.push_back(mul / sieve.primes[i] / sieve.primes[j]);
		}
		
	}

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}