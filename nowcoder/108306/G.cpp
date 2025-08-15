#include <bits/stdc++.h>

using i64 = long long;

struct TREE {
	std::vector<int> tree;
	int sz;

	inline int lowbit(int x) {
		return x & (-x);
	}

	void add(int x, i64 k) {
		for (; x <= sz; x += lowbit(x)) {
			tree[x] += k;
		}
	}

	void build(std::vector<int> a) {
		sz = a.size() - 1;
		tree.resize(sz + 1);
		for (int i = 1; i <= sz; i++) {
			add(i, a[i]);
		}
	}

	i64 queryP(int x) {
		i64 ans = 0;
		for (; x; x -= lowbit(x)) {
			ans = ans + tree[x];
		}
		return ans;
	}

	i64 sum(int x, int y) {
		return queryP(y) - queryP(x - 1);
	}
};

struct NODE {
	int sz; // 搜索序列中数的个数
	int l, r; // 极大合法区间
};

constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p) {
	return qpow(x, p - 2, p);
}

i64 pw[2000005];

i64 C(i64 n, i64 m) {
	return pw[n] * inv(pw[m], mod) % mod * inv(pw[n - m], mod) % mod;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1), pos(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
		pos[p[i]] = i;
	}

	TREE tree; std::vector<int> ___(n + 1);
	tree.build(___);

	std::vector<std::pair<int, int>> range(n + 1, {1, n});
	for (int i = 1; i <= n; i++) {
		// 1 ~ pos[i] - 1, pos[i] + 1 ~ n
		int lo = 1, hi = pos[i];
		int ansl = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (tree.sum(mid, pos[i]) == 0) {
				hi = mid - 1;
				ansl = mid;
			} else {
				lo = mid + 1;
			}
		}

		lo = pos[i], hi = n;
		int ansr = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (tree.sum(pos[i], mid) == 0) {
				lo = mid + 1;
				ansr = mid;
			} else {
				hi = mid - 1;
			}
		}

		range[i] = {ansl, ansr};
		// std::cerr << "range" << i << " = " << ansl << " " << ansr << '\n';

		tree.add(pos[i], 1);
	}

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = n; i >= 1; i--) {
		for (int j = i - 1; j >= 1; j--) {
			if (range[i].first >= range[j].first && range[i].second <= range[j].second) {
				edge[j].push_back(i);
				// std::cerr << j << "->" << i << '\n';
				break;
			}
		}
	}

	std::vector<int> depth(n + 1);
	std::queue<int> q;
	q.push(1);
	depth[1] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto to : edge[now]) {
			q.push(to);
			depth[to] = depth[now] + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cerr << i << " " << depth[i] << " " << range[i].first << " " << range[i].second << '\n';
	}

	i64 ans = 1;
	for (int i = 1; i <= n; i++) {
		int used = range[i].second - range[i].first + 1;
		std::cerr << C(used + depth[i] - 1, depth[i]) << '\n';
		// used 次 query 机会, depth[i] 个数
		ans = (ans + C(used + depth[i] - 1, depth[i])) % mod;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 2000000; i++) {
		pw[i] = pw[i - 1] * i % mod;
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

/*
cnt = 15

1 
1 1 
1 1 1 
1 1 1 1 
1 1 1 1 1 
1 1 3 
1 3 
1 3 3 
2 
3 
3 3 
3 3 3 
4 
5 
*/