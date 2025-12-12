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

constexpr int M = 3e5;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::map<i64, std::vector<int>>> adj(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u][a[v]].push_back(v);
		// std::cerr << u << " " << a[v] << " : " << v << '\n';
	}

	for (int i = 1; i <= n; i++) {
		adj[0][a[i]].push_back(i);
	}

	std::vector<std::map<i64, Z>> ans(n + 1), maxlen(n + 1);
	for (int i = 1; i <= n; i++) {
		ans[i][0] = 1, maxlen[i][0] = 1;
	}

	std::map<std::pair<i64, int>, bool> vis;
	std::stack<std::pair<i64, int>> q;
	for (int i = 1; i <= n; i++) {
		q.push({0, i});
		vis[{0, i}] = 1;
	}

	int cnt = 0;

	while (!q.empty()) {
		cnt++;
		auto [prev, now] = q.top();
		vis[{prev, now}] = 0;
		q.pop();

		if (prev == 0) {
			for (auto[val, tovec] : adj[now]) {
				for (auto to : tovec) {
					// std::cerr << now << "->" << to << '\n';
					ans[to][a[now]] += maxlen[now][prev];
					maxlen[to][a[now]] = maxlen[now][prev];
					if (!vis[{a[now], to}]) {
						q.push({a[now], to});
						vis[{a[now], to}] = 1;
					}
				}
			}
		} else {
			for (auto to : adj[now][prev + a[now]]) {
				// std::cerr << now << "->" << to << '\n';
				ans[to][a[now]] += maxlen[now][prev];
				maxlen[to][a[now]] = maxlen[now][prev];
				if (!vis[{a[now], to}]) {
					q.push({a[now], to});
					vis[{a[now], to}] = 1;
				}
			}
		}
	}	

	// std::cerr << "opcnt = " << cnt << '\n';

	Z sum = 0;
	for (int i = 1; i <= n; i++) {
		for (auto [nd, as] : ans[i]) {
			if (nd == 0) {
				continue;
			}
			sum += as;
		}
	}
	std::cout << sum << '\n';
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