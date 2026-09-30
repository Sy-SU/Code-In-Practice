#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

template<class Info, class Tag>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    explicit SegmentTree(const std::vector<i64>& a) {
        n = (int)a.size() - 1;
        info.assign(4 * n + 10, Info()), tag.assign(4 * n + 10, Tag());
        if (n) {
            build(1, 1, n, a);
        }
    }

    void modify(int L, int R, i64 val) {
        if (L > R || n == 0) {
            return;
        }
        modify(1, 1, n, L, R, Tag(val));
    }

    Info query(int L, int R) {
        if (L > R) {
            return Info();
        }
        return query(1, 1, n, L, R);
    }

private:
    void pushup(int u) {
        info[u] = info[u << 1] + info[u << 1 | 1];
    }

    void apply(int u, const Tag &t) {
        info[u].apply(t), tag[u].apply(t); 

    }

    void pushdown(int u) {
        apply(u << 1, tag[u]), apply(u << 1 | 1, tag[u]);
        tag[u] = Tag();
    }

    void build(int u, int l, int r, const std::vector<i64>& a) {
        if (l == r) {
            info[u] = Info(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        pushup(u);
    }

    void modify(int u, int l, int r, int L, int R, const Tag &t) {
        if (L <= l && r <= R) {            
            apply(u, t);
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        if (L <= mid) {
            modify(u << 1, l, mid, L, R, t);
        }
        if (R > mid) {
            modify(u << 1 | 1, mid + 1, r, L, R, t);
        }
        pushup(u);
    }

    Info query(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return info[u];
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        Info res = Info();
        if (L <= mid) {
            res = res + query(u << 1, l, mid, L, R);
        }
        if (R > mid) {
            res = res + query(u << 1 | 1, mid + 1, r, L, R);
        }
        return res;
    }
};

struct Tag {
    // Lazy tag，例如区间加法，区间乘法
    i64 upd; // 区间加法

    Tag() : upd(INF) {}
    Tag(i64 x) : upd(x) {}

    void apply(const Tag &oth) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        upd = std::min(upd, oth.upd);
    }
};

struct Info {
    // 需要维护的信息，例如区间和，区间最值
    i64 min;
    int cnt; // 区间长度

    Info() : min(INF), cnt(0) {}
    Info(i64 x) : min(x), cnt(1) {}
    Info(i64 min, int cnt) : min(min), cnt(cnt) {}

    Info operator+(const Info &oth) const {
        return {std::min(min, oth.min), cnt + oth.cnt};
    }

    void apply(const Tag &tag) {
        // 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
        min = std::min(min, tag.upd);
    }
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> G(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch;
			std::cin >> ch;

			G[i][j] = ch - '0';
		}
 	}

 	bool isswap = 0;
 	if (n < m) {
 		std::vector<std::vector<int>> GG(m + 1, std::vector<int>(n + 1));
 		for (int i = 1; i <= n; i++) {
 			for (int j = 1; j <= m; j++) {
 				GG[j][i] = G[i][j];
 			}
 		}

 		G = GG;
 		std::swap(n, m);
 		isswap = 1;
 	}

 	std::vector<std::vector<int>> pre(m * (m - 1) / 2 + 1, std::vector<int>(n + 1));
 	for (int j1 = 1; j1 <= m; j1++) {
 		for (int j2 = j1 + 1; j2 <= m; j2++) {
 			// (j1, j2) -> j2 - j1 + (2 * m - j1) * (j1 - 1) / 2
 			int ind = j2 - j1 + (2 * m - j1) * (j1 - 1) / 2;
 			// std::cerr << j1 << " " << j2 << " -> " << ind << '\n';
 			for (int i = 1; i <= n; i++) {
 				pre[ind][i] = pre[ind][i - 1] + (G[i][j1] && G[i][j2]);
 			}
 		}
 	}

 	std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(m + 2, std::vector<int>(m + 2, 1e9)));

 	for (int j1 = 1; j1 <= m; j1++) {
 		for (int j2 = j1 + 1; j2 <= m; j2++) {
		 	int lst = -1;
		 	for (int i = 1; i <= n; i++) {
		 		if (G[i][j1] + G[i][j2] == 2) {
		 			if (lst == -1) {
		 				lst = i;
		 				continue;
		 			}
		 			int area = (j2 - j1 + 1) * (i - lst + 1);
		 			// std::cerr << "find" << lst << " " << i << " " << j1 << " " << j2 << " " << area << '\n';
 				
	 				for (int col = lst; col <= i; col++) {
	 					// std::cerr << col << " " << j1 << " " << j2 << " " << area << '\n';
	 					dp[col][j1][j2] = std::min(dp[col][j1][j2], area);
	 				}
		 			lst = i;
		 		}
		 	}
 		}
 	}
 	for (int i = 1; i <= n; i++) {
 		for (int len = m - 1; len >= 1; len--) {
 			for (int l = 1; l + len - 1 <= m; l++) {
 				int r = l + len - 1;
 				dp[i][l][r] = std::min({dp[i][l][r], dp[i][l - 1][r], dp[i][l][r + 1]});
 			}
 		}
 	}

 	if (isswap) {
 		for (int j = 1; j <= m; j++) {
	 		for (int i = 1; i <= n; i++) {
	 			i64 x = dp[i][j][j];
	 			if (x >= 1e9) {
	 				x = 0;
	 			}
	 			std::cout << x << " \n"[i == n];
	 		}
	 	}
	 	return;
 	}

 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			i64 x = dp[i][j][j];
 			if (x >= 1e9) {
 				x = 0;
 			}
 			std::cout << x << " \n"[j == m];
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