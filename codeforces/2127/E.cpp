#include <bits/stdc++.h>

using i64 = long long;
void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> w(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::vector<int> fa(n + 1), dep(n + 1), son(n + 1), sz(n + 1), top(n + 1);

	auto dfs1 = [&](auto &&self, int u, int father) -> void {
		fa[u] = father;
		dep[u] = dep[father] + 1;
		sz[u] = 1;
		for (auto to : edge[u]) {
			if (to == father) {
				continue;
			}
			self(self, to, u);
			sz[u] += sz[to];
			if (sz[son[u]] < sz[to]) {
				son[u] = to;
			}
		}
	};

	auto dfs2 = [&](auto &&self, int u, int t) -> void {
		top[u] = t;
		if (son[u] == 0) {
			return;
		}
		self(self, son[u], t);
		for (auto to : edge[u]) {
			if (to == fa[u] || to == son[u]) {
				continue;
			}
			self(self, to, to);
		}
	};

	auto lca = [&](int u, int v) -> int {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	};

	dfs1(dfs1, 1, 0);
	dfs2(dfs2, 1, 1);

	std::vector<int> facol(n + 1), leaf(n + 1); // 最近的一个有颜色的父节点的颜色
	facol[1] = c[1];

	auto dfs3 = [&](auto &&self, int u, int fa) -> void {
		int _l = 0;
		for (auto v : edge[u]) {
			if (fa == v) {
				continue;
			}
			self(self, v, u);
			_l++;
			if (c[u]) {
				facol[v] = c[u];
			} else {
				facol[v] = facol[u];
			}
		}
		if (_l == 0) {
			leaf[u] = 1;
		}
	};

	dfs3(dfs3, 1, 0);

	for (int i = 1; i <= n; i++) {
		if (leaf[i]) {
			int now = i;
			while (c[now] == 0) {
				c[now] = facol[now] ? facol[now] : 1;
				now = fa[now];
			}
		}
	}

	auto dfs4 = [&](auto &&self, int u, int fa) -> void {
		for (auto v : edge[u]) {
			if (fa == v) {
				continue;
			}
			self(self, v, u);
			if (c[u] == 0) {
				c[u] = c[v];
			}
		}
	};

	dfs4(dfs4, 1, 0);

	std::map<int, std::map<int, int>> col;

	i64 ans = 0;

	auto dfs5 = [&](auto &&self, int u, int fa) -> void {
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
			for (auto [cc, num] : col[v]) {
				col[u][cc]++;
			}
		}

		bool isok = 0;
		for (auto [cc, num] : col[u]) {
			// std::cerr << u << "\n";
			// std::cerr << cc << " " << num << '\n';
			if (cc != c[u] && num >= 2) {
				isok = 1;
			}
		}
		if (isok) {
			// std::cerr << "cute " << u << '\n';
			ans += w[u];
		}

		col[u][c[u]]++;
	};

	dfs5(dfs5, 1, 0);

	std::cout << ans << '\n';

	for (int i = 1; i <= n; i++) {
		std::cout << c[i] << " \n"[i == n];
	}
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

template<int MOD>
struct ModInt {
    /*
    using Z = ModInt<998244353>;

    int main() {
        Z a = 2, b = 3;
        cout << a + b << "\n";    // 5
        cout << a * b << "\n";    // 6
        cout << a / b << "\n";    // 2 * inv(3)
        cout << a.pow(10) << "\n"; // 1024
    }
    */

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