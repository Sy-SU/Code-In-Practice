#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[p[i]] = i;
	}

	for (int v = n; v >= 3; v--) {
		int i1 = ind[v], i2 = ind[v - 1], i3 = ind[v - 2];
		if (i1 < i2 && i1 < i3) {
			p[i1] -= 2, p[i2]++, p[i3]++;
			ind[p[i1]] = i1, ind[p[i2]] = i2, ind[p[i3]] = i3;
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << p[i] << " \n"[i == n];
		// }
	}

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
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