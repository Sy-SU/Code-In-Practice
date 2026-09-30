#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, l;
	std::cin >> n >> m >> l;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> vis(l + 1);
	for (int i = 1; i <= n; i++) {
		vis[a[i]] = 1;
	}

	int x = 0, opcnt = n;

	std::vector<int> d(m + 1);
	for (int t = 1; t <= l; t++) {
		std::sort(d.begin() + 1, d.end(), std::greater<int>());

		// for (int i = 1; i <= m; i++) std::cerr << d[i] << " \n"[i == m];

		int minv = 1e9, mini = 1;
		for (int i = 1; i <= std::min(opcnt + 1, m); i++) {
			if (d[i] < minv) {
				minv = d[i], mini = i;
			}
		}

		d[mini]++;

		if (vis[t]) {
			int maxv = -1, maxi = 1;
			for (int i = 1; i <= m; i++) {
				if (d[i] > maxv) {
					maxv = d[i], maxi = i;
				}
			}
			d[maxi] = 0;

			opcnt--;
		}
	}

	for (int i = 1; i <= m; i++) {
		x = std::max(x, d[i]);
	}

	std::cout << x << '\n';
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