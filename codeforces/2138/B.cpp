#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> l(n + 1), r(n + 1);
	std::stack<int> stk;
	for (int i = 1; i <= n; i++) {
		while (!stk.empty() && a[stk.top()] < a[i]) {
			stk.pop();
		}
		l[i] = stk.empty() ? -1 : stk.top();
		stk.push(i);
	}

	while (!stk.empty()) {
		stk.pop();
	}

	for (int i = n; i >= 1; i--) {
		while (!stk.empty() && a[stk.top()] > a[i]) {
			stk.pop();
		}
		r[i] = stk.empty() ? (n + 1) : stk.top();
		stk.push(i);
	}

	std::vector<int> f(n + 1, n + 1);
	for (int i = 1; i <= n; i++) {
		if (l[i] != -1) {
			f[l[i]] = std::min(f[l[i]], r[i] - 1);
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		f[i] = std::min(f[i], f[i + 1]);
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;

		std::cout << (f[l] >= r ? "YES" : "NO") << '\n';
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