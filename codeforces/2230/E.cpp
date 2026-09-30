#include <bits/stdc++.h>

using i64 = long long;

struct News {
	i64 p, c;
};

struct Users {
	i64 tp, tc, d;
};

constexpr i64 INF = 1e18;

template<class Info, class Tag>
struct SegmentTree {
	/*
	线段树维护区间加，查询区间和，区间最值
	使用 SegmentTree<Info, Tag> st(a); 初始化线段树
	区间加: st.modify(L, R, val);
	查询区间和: st.query(L, R).sum;
	查询区间最大值: st.query(L, R).max;
	查询区间最小值: st.query(L, R).min;
	*/
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
	i64 add; // 区间加法

	Tag() : add(0) {}
	Tag(i64 x) : add(x) {}

	void apply(const Tag &oth) {
		// 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
		add += oth.add;
	}
};

struct Info {
	// 需要维护的信息，例如区间和，区间最值
	i64 min, max, sum;
	int cnt; // 区间长度

	Info() : min(INF), max(-INF), sum(0), cnt(0) {}
	Info(i64 x) : min(x), max(x), sum(x), cnt(1) {}
	Info(i64 min, i64 max, i64 sum, int cnt) : min(min), max(max), sum(sum), cnt(cnt) {}

	Info operator+(const Info &oth) const {
		return {std::min(min, oth.min), std::max(max, oth.max), sum + oth.sum, cnt + oth.cnt};
	}

	void apply(const Tag &tag) {
		// 如果更换维护的更改操作（例如区间加法，区间乘法，区间赋值），需要更改这里
		min += tag.add, max += tag.add, sum += cnt * 1ll * tag.add;
	}
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<News> news(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> news[i].p;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> news[i].c;
	}

	int m;
	std::cin >> m;

	std::vector<Users> users(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> users[i].tp;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> users[i].tc;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> users[i].d;
	}

	auto pnews = news;
	auto cnews = news;
	auto pcnews = news;

	std::sort(pnews.begin() + 1, pnews.end(), [](News n1, News n2) {
		return n1.p == n2.p ? n1.c < n2.c : n1.p < n2.p;
	});
	std::sort(cnews.begin() + 1, cnews.end(), [](News n1, News n2) {
		return n1.c == n2.c ? n1.p < n2.p : n1.c < n2.c;
	});
	std::sort(pcnews.begin() + 1, pcnews.end(), [](News n1, News n2) {
		return (n1.p + n1.c) < (n2.p + n2.c);
	});

	std::vector<i64> cinp(n + 1);
	for (int i = 1; i <= n; i++) {
		cinp[i] = pnews[i].c;
	}
	SegmentTree<Info, Tag> cinpTree(cinp);

	std::vector<i64> pinc(n + 1);
	for (int i = 1; i <= n; i++) {
		pinc[i] = cnews[i].p;
	}
	SegmentTree<Info, Tag> pincTree(pinc);
	
	for (int q = 1; q <= m; q++) {
		auto [tp, tc, d] = users[q];

		i64 minans = 1e18;

		{
			int lo = 1, hi = n, fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (pnews[mid].p < tp) {
					fd = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (fd != -1) {
				i64 cmin = cinpTree.query(1, fd).min;
				if (cmin < tc) {
					cmin = 0;
				} else if (cmin >= tc + d) {
					cmin = tc + d;
				}
				// std::cerr << 0 << " " << cmin << '\n';
				minans = std::min(minans, 0 + cmin);
			}
		}

		{
			int lo = 1, hi = n, fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (pnews[mid].p >= tp + d) {
					fd = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			if (fd != -1) {
				i64 cmin = cinpTree.query(fd, n).min;				
				if (cmin < tc) {
					cmin = 0;
				} else if (cmin >= tc + d) {
					cmin = tc + d;
				}
				minans = std::min(minans, tp + d + cmin);
				// std::cerr << tp + d << " " << cmin << '\n';
			}
		}

		{
			int lo = 1, hi = n, fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (cnews[mid].c < tc) {
					fd = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (fd != -1) {
				i64 pmin = pincTree.query(1, fd).min;				
				if (pmin < tp) {
					pmin = 0;
				} else if (pmin >= tp + d) {
					pmin = tp + d;
				}
				minans = std::min(minans, 0 + pmin);
				// std::cerr << 0 << " " << pmin << '\n';
			}
		}

		{
			int lo = 1, hi = n, fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (cnews[mid].c >= tc + d) {
					fd = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			if (fd != -1) {
				i64 pmin = pincTree.query(fd, n).min;
				if (pmin < tp) {
					pmin = 0;
				} else if (pmin >= tp + d) {
					pmin = tp + d;
				}
				minans = std::min(minans, tc + d + pmin);
				// std::cerr << tc + d << " " << pmin << '\n';
			}
		}

		{
			minans = std::min(minans, pcnews[1].p + pcnews[1].c);
		}

		std::cout << minans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}