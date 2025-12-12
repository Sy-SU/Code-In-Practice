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

struct DSU {
    int n;
    std::vector<int> fa, sz;

    explicit DSU(int n) {
        fa.assign(n + 1, 0), sz.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        if (sz[fx] < sz[fy]) {
            std::swap(fx, fy);
        }
        fa[fy] = fx;
        sz[fx] += sz[fy];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
	int n, m, V;
	std::cin >> n >> m >> V;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> adj(n + 1);
	std::vector<std::pair<int, int>> edge;
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
		edge.push_back({u, v});
	}

	std::vector<int> dfn(n + 1), low(n + 1), scc(n + 1), siz(n + 1);
	int tot, cnt;
	std::map<std::pair<int, int>, int> bridge;

	auto tarjan = [&](auto &&self, int u, int fa) -> void {
		dfn[u] = low[u] = ++tot;
		for (auto v : adj[u]) {
			if (!dfn[v]) {
				self(self, v, u);
				low[u] = std::min(low[u], low[v]);
				if (low[v] > dfn[u]) {
					bridge[{u, v}] = 1;
				}
			} else if (v != fa) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	};

	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			tarjan(tarjan, i, 0);
		}
	}

	// for (auto [ed, vi] : bridge) {
	// 	auto [u, v] = ed;
	// 	std::cerr << u << " " << v << '\n';
	// }

	adj.assign(n + 1, {});

	DSU dsu(n);
	for (auto [u, v] : edge) {
		if (bridge[{u, v}] || bridge[{v, u}]) {
			continue;
		}
		dsu.merge(u, v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<int> num(n + 1, -1e9);
	for (int i = 1; i <= n; i++) {
		// 每个 BCC 中最大的 val
		num[dsu.find(i)] = std::max(num[dsu.find(i)], a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] != -1) {
			if (a[i] != num[dsu.find(i)]) {
				std::cout << 0 << '\n';
				return;
			}
		}
	}

	// 判断每个 BCC 中是否存在奇环
	// 如果存在，这个 BCC 只能全部为 0 -> type = 1
	// 如果不存在，这个 BCC 只能全部为一种权值 -> type = 0

	std::vector<int> col(n + 1, -1);
	std::vector<int> type(n + 1);
	for (int i = 1; i <= n; i++) {
		if (col[i] != -1) {
			continue;
		}

		auto dfs = [&](auto &&self, int u, int fa) -> void {
			for (auto v : adj[u]) {
				if (v == fa) {
					continue;
				}
				if (col[v] != -1) {
					if (col[v] == col[u]) {
						type[dsu.find(u)] = 1;
					}
					continue;
				}
				col[v] = 1 - col[u];
				self(self, v, u);
			}
		};

		col[i] = 1;
		dfs(dfs, i, 0);
	}

	std::vector<std::vector<int>> val(n + 1);
	for (int i = 1; i <= n; i++) {
		val[dsu.find(i)].push_back(a[i]);
		// std::cerr << "val" << dsu.find(i) << "<-" << i << " " << a[i] << "\n";
	}

	Z ans = 1;
	for (int bcc = 1; bcc <= n; bcc++) {
		auto vec = val[bcc];
		if (vec.empty()) {
			continue;
		}

		if (type[bcc]) {
			for (auto v : vec) {
				if (v != 0 && v != -1) {
					std::cout << 0 << '\n';
					return;
				}
			}
		} else {
			int cnt = 0, sz = vec.size();
			for (auto v : vec) {
				if (v == -1) {
					cnt++;
				}
			}
			if (cnt == sz) {
				ans *= V;
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