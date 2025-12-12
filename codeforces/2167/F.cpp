#include <bits/stdc++.h>

using i64 = long long;

template<class T>
struct Fenwick {
    /*
    树状数组维护单点加，区间和
    使用 Fenwick<i64> tree(a); 初始化树状数组
    单点加: tree.add(pos, val);
    区间和: tree.sum(l, r)
    */
    int n;
    std::vector<T> tr;

    Fenwick() {
        n = 0;
        tr.assign(n + 1, T());
    }

    explicit Fenwick(const std::vector<T> &a) {
        n = a.size() - 1;
        tr.assign(n + 1, T());
        if (n) {
            for (int i = 1; i <= n; ++i) {
                tr[i] += a[i];
                int j = i + (i & -i);
                if (j <= n) tr[j] += tr[i];
            }
        }
    }

    void add(int pos, const T &val) {
        for (int i = pos; i <= n; i += i & -i) {
            tr[i] += val;
        }
    }

    T prefix(int pos) {
        T res = T();
        for (int i = pos; i; i -= i & -i) {
            res += tr[i];
        }
        return res;
    }

    T sum(int l, int r) {
        if (l > r) {
            return T();
        }
        return prefix(r) - prefix(l - 1);
    }
};

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<int> son(n + 1);

	auto dfs = [&](auto &&self, int u, int f) -> void {
		son[u] = 1;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			son[u] += son[v];
		}
	};

	dfs(dfs, 1, 0);

	std::vector<i64> help(n + 2);
	for (int i = 1; i <= n; i++) {
		help[son[i] + 1]++;
	}
	Fenwick<i64> tree(help);
	// std::cerr << "ok" << '\n';
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << son[i] << " ";
	// }
	// std::cerr << '\n';
	// for (int i = 1; i <= n + 1; i++) {
	// 	std::cerr << tree.sum(i, i) << " \n"[i == n + 1];
	// }

	i64 ans = tree.sum(k + 1, n + 1);

	auto dfs1 = [&](auto &&self, int u, int f) -> void {
		if (f) {
			tree.add(son[f] + 1, -1), tree.add(n - son[u] + 1, 1);
			son[f] = n - son[u];

			// son[f] -> n - son[u], son[u] -> n
			ans += tree.sum(k + 1, n + 1);
			if (son[u] < k) {
				ans++;
			}

			// std::cerr << "r = " << u << '\n';
			// for (int i = 1; i <= n; i++) {
			// 	if (i == u) {
			// 		std::cerr << n << ' ';
			// 	} else {
			// 		std::cerr << son[i] << " ";
			// 	}
			// }
			// std::cerr << '\n';
			// for (int i = 1; i <= n + 1; i++) {
			// 	std::cerr << tree.sum(i, i) << " \n"[i == n + 1];
			// }
			// std::cerr << "cnt = " << tree.sum(k + 1, n + 1) << '\n';
		}
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			tree.add(son[v] + 1, -1), tree.add(n - son[u] + 1, 1);
			son[v] = n - son[u];
		}
	};

	dfs1(dfs1, 1, 0);

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