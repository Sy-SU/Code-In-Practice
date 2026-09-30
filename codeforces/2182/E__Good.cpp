#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int x;
	i64 more;
};

void solve() {
	int n, m;
	i64 k;
	std::cin >> n >> m >> k;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::vector<Node> node(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		i64 y, z;
		std::cin >> x >> y >> z;

		node[i] = {x, z - y};
		k -= y;
	}

	int ans = 0;

	i64 sss = pow(m + 2, n);
	for (int s = 0; s < sss; s++) {
		i64 now = s;
		int cnt = 0;
		i64 usedk = 0;
		bool isvalid = 1;
		std::vector<int> visa(m + 1);
		for (int i = 1; i <= n; i++) {
			i64 ns = now % (m + 2);
			now /= (m + 2);

			if (ns == 0) {
				continue;
			}
			if (ns == m + 1) {
				cnt++;
				usedk += node[i].more;
			}
			if (ns <= m && ns >= 1) {
				if (visa[ns]) {
					isvalid = 0;
				} else {
					visa[ns] = 1;
					if (a[ns] >= node[i].x) {
						cnt++;
					} else {
						isvalid = 0;
					}
				}
			}
		}
		if (usedk > k) {
			isvalid = 0;
		}
		if (isvalid == 0) {
			continue;
		}
		ans = std::max(ans, cnt);
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