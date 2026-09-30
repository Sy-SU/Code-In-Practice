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
		// std::cerr << "add " << pos << " " << val << '\n';
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
		// std::cerr << "sum " << l << " " << r << '\n';
		if (l > r) {
			return T();
		}
		return prefix(r) - prefix(l - 1);
	}
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	// std::cerr << "ok" << '\n';
	// std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1));
	// dp[0][0] = 1;

	std::vector<i64> d(n + 2);
	Fenwick<i64> fwk(d);
	// std::cerr << "ok" << '\n';

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) {
			int j = a[i];
			fwk.add(j + 1, fwk.sum(j - 1 + 1, j - 1 + 1));
			// std::cerr << "add " << i << " " << j << " " << fwk.sum(j - 1 + 1, j - 1 + 1) << '\n';
			if (j == 1) {
				fwk.add(j + 1, 1);
			}
		}

		int aj = a[i] - 1, bj = b[i] - 1;
		if (aj == bj) {
			int va = fwk.sum(aj + 1, aj + 1);
			fwk.add(aj + 1, -va);
		} else {
			int va = fwk.sum(aj + 1, aj + 1);
			fwk.add(aj + 1, -va);

			int vb = fwk.sum(bj + 1, bj + 1);
			fwk.add(bj + 1, -vb);
		}

		if (aj != 0 && bj != 0) {
			fwk.add(0 + 1, 1);
		}

		ans += fwk.sum(0 + 1, n + 1);

		// {
		// 	for (int j = 0; j <= n; j++) {
		// 		std::cerr << "fwk " << i << " " << j << " = " << fwk.sum(j + 1, j + 1) << '\n';
		// 	}
		// }
	}
	std::cout << ans << '\n';

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		if (a[i] == j && b[i] == j) {
	// 			dp[i][j] += dp[i - 1][j - 1]; 
	// 			if (j == 1) {
	// 				dp[i][j]++;
	// 			}
	// 		}
	// 		if (a[i] != j + 1 && b[i] != j + 1) {
	// 			dp[i][j] += dp[i - 1][j];
	// 			if (j == 0) {
	// 				dp[i][j]++;
	// 			}
	// 		}
	// 	}
	// } 

	// i64 sum = 0;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		sum += dp[i][j];
	// 		std::cerr << "dp " << i << " " << j << " = " << dp[i][j] << '\n';
	// 	}
	// }

	// std::cout << sum << '\n';
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