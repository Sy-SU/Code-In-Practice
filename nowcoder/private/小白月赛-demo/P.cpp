#include <bits/stdc++.h>
 
using i64 = long long;
 
struct SegmentTree {
    struct NODE {
        int l, r;
        i64 sum = 0, lazy = 0;
    };

    std::vector<NODE> node;
    int n;

    SegmentTree(const std::vector<i64> &a) {
        n = (int)a.size() - 1; // 1-index
        node.resize(4 * n + 4);
        build(1, 1, n, a);
    }

    void pushup(int u) {
        node[u].sum = node[u << 1].sum + node[u << 1 | 1].sum;
    }

    void pushdown(int u) {
        if (node[u].lazy) {
            i64 tag = node[u].lazy;
            node[u << 1].sum += tag * (node[u << 1].r - node[u << 1].l + 1);
            node[u << 1 | 1].sum += tag * (node[u << 1 | 1].r - node[u << 1 | 1].l + 1);
            node[u << 1].lazy += tag;
            node[u << 1 | 1].lazy += tag;
            node[u].lazy = 0;
        }
    }

    void build(int u, int l, int r, const std::vector<i64>& a) {
        node[u].l = l;
        node[u].r = r;
        if (l == r) {
            node[u].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        pushup(u);
    }

    void add(int u, int l, int r, i64 val) {
        if (l <= node[u].l && node[u].r <= r) {
            node[u].sum += val * (node[u].r - node[u].l + 1);
            node[u].lazy += val;
            return;
        }
        pushdown(u);
        int mid = (node[u].l + node[u].r) >> 1;
        if (l <= mid){
        	add(u << 1, l, r, val);
        }
        if (r > mid) {
        	add(u << 1 | 1, l, r, val);
        }
        pushup(u);
    }

    i64 getsum(int u, int l, int r) {
        if (l <= node[u].l && node[u].r <= r) {
            return node[u].sum;
        }
        pushdown(u);
        int mid = (node[u].l + node[u].r) >> 1;
        i64 sum = 0;
        if (l <= mid) {
        	sum += getsum(u << 1, l, r);
        }
        if (r > mid) {
        	sum += getsum(u << 1 | 1, l, r);
        }
        return sum;
    }

    void opAdd(int l, int r, i64 val) {
        add(1, l, r, val);
    }

    i64 opGetSum(int l, int r) {
        return getsum(1, l, r);
    }
};


void solve() {
	int n, q, s;
	std::cin >> n >> q >> s;
 
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
 
	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
 
		edge[u].push_back(v), edge[v].push_back(u);
	}
 
    std::vector<int> depth(n + 1), fat(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        depth[u] = depth[fa] + 1, fat[u] = fa;
        for (const auto &v : edge[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
 
    // depth[s] = 1;
    dfs(dfs, s, 0);
 
    while (q--) {
        int op;
        std::cin >> op;
 
        if (op == 1) {
            int o, k;
            i64 x;
            std::cin >> o >> k >> x;
 
           
        } else {
            int o;
            std::cin >> o;
 
            
        }
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
