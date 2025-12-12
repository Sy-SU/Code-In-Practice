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

using Z = ModInt<998244353>;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::pair<int, int>> edge(m + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[i] = {u, v};
	}

	std::sort(edge.begin() + 1, edge.end(), [&](std::pair<int, int> p1, std::pair<int, int> p2) {
		return a[p1.second] < a[p2.second];
	});

	std::map<i64, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<std::map<i64, Z>> dp(n + 1);
	for (int i = 1; i <= m; i++) {
		auto [u, v] = edge[i];
		if (a[u] <= a[v]) {
			dp[v][a[u]] += dp[u][a[v] - a[u]];
			// std::cerr << "dp" << v << " " << a[u] << " = " << dp[v][a[u]] << '\n';
		}
		dp[v][a[u]] += 1;
		// std::cerr << "dp" << v << " " << a[u] << " = " << dp[v][a[u]] << '\n';
	}

	Z ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto [v, sum] : dp[i]) {
			ans += sum;
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