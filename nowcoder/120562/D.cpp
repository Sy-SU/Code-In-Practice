#include <bits/stdc++.h>

using i64 = long long;

template<int MOD>
struct ModInt {
    static_assert(MOD > 0, "MOD must be positive");

    int v;

    ModInt() : v(0) {}
    template<class T>
    ModInt(T x) {
        long long t = (long long)x % MOD;
        if (t < 0) t += MOD;
        v = (int)t;
    }

    static constexpr int mod() { return MOD; }
    int val() const { return v; }

    ModInt& operator+=(const ModInt& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& o) {
        v = (int)((__int128)v * o.v % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& o) {
        return *this *= o.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
    ModInt operator-() const { return ModInt(v ? MOD - v : 0); }

    friend bool operator==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.v != b.v; }

    ModInt pow(long long e) const {
        ModInt res = 1, base = *this;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        return pow(MOD - 2);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        return os << a.v;
    }
    friend std::istream& operator>>(std::istream& is, ModInt& a) {
        long long x; is >> x;
        a = ModInt(x);
        return is;
    }
};

using Z = ModInt<1000000007>;

struct Node {
	Z val;
	int zero;

	Z v() {
		if (zero) {
			return 0;
		} else {
			return val;
		}
	}
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), ind(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];

		ind[a[i]] = i;
	}

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<Z> dp(n + 1, 1);
	std::vector<int> fa(n + 1);
	auto dfs = [&](auto &&self, int u, int f) -> void {
		fa[u] = f;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			dp[u] *= (dp[v] + 1);
		}
	};

	dfs(dfs, ind[0], 0);

	Z ans = 0;

	std::vector<Node> mx(n + 2);
	if (dp[ind[0]] == 0) {
		mx[1] = {0, 1};
	} else {
		mx[1] = {dp[ind[0]], 0};
	}

	std::vector<int> must(n + 1);
	must[ind[0]] = 1;

	auto bo = dp;

	for (int i = 2; i <= n; i++) {
		// std::cerr << "======" << i << '\n';
		// i - 1 -> i
		mx[i] = mx[i - 1];
		int now = ind[i - 1];
		if (must[now]) {
			continue;
		}

		while (1) {
			must[now] = 1;
			// std::cerr << "must choose " << a[now] << '\n';
			if (fa[now] == 0) {
				break;
			}

			if (dp[now] != 0) {
				mx[i].val *= dp[now];
			} else {
				mx[i].zero++;
			}

			if (dp[now] + 1 != 0) {
				mx[i].val /= (dp[now] + 1);
			} else {
				mx[i].zero--;
			}

			now = fa[now];

			if (now == 0 || must[now] == 1) {
				break;
			}
		}
	}

	// for (int i = 0; i <= n + 1; i++) {
	// 	std::cerr << "mx" << i << " = " << mx[i] << '\n';
	// }

	for (int i = 1; i <= n; i++) {
		ans += i * (mx[i].v() - mx[i + 1].v());
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}