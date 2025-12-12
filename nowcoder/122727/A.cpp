#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), std::greater<int>());

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 3) {
			res += a[i] - 2;
			a[i] = 2;
		} else {
			if (res > 0 && (a[i] % 2)) {
				a[i]++, res--;
			}
		}
	}

	a[n] += res;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] % 2 == 0;
	}
	std::cout << cnt << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}