#include <bits/stdc++.h>

using i64 = long long;

template<class T>
struct Fenwick {
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
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::vector<int> h(n + 1);
	Fenwick f(h);

	int ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += p[i] <= i;
		ans = std::max(ans, f.sum(i + 1, n) + sum);
		f.add(p[i], 1);
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