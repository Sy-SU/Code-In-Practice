#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<i64> dpa(n + 1, 1e18), dpb(n + 1, 1e18);
	std::priority_queue<i64> pqa;
	i64 suma = 0;
	for (int i = 1; i <= n; i++) {
		pqa.push(a[i]);
		suma += a[i];
		if (pqa.size() == m + 1) {
			suma -= pqa.top();
			pqa.pop();
		}

		if (pqa.size() == m) {
			dpa[i] = suma;
		}
	}
	std::priority_queue<i64> pqb;
	i64 sumb = 0;
	for (int i = n; i >= 1; i--) {
		pqb.push(b[i]);
		sumb += b[i];

		if (pqb.size() == m + 1) {
			sumb -= pqb.top();
			pqb.pop();
		}

		if (pqb.size() == m) {
			dpb[i] = sumb;
		}

	}

	i64 ans = 1e18;
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, dpa[i - 1] + dpb[i]);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}