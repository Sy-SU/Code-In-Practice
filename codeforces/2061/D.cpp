#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1, 0), b(m + 1, 0);
	std::map<i64, int> cnta, cntb;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		cnta[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
		cntb[b[i]]++;
	}
	for (const auto &[num, cnt] : cnta) {
		int min = std::min(cnt, cntb[num]);
	}

	int sz = 0;
	for (const auto &[num, cnt] : cnta) {
		sz += cnt;
	}

	for (const auto &[num, cnt] : cntb) {
		for (int i = 1; i <= cnt; i++) {
			std::queue<i64> q;
			q.push(num);
			while (!q.empty()) {
				i64 now = q.front();
				q.pop();

				if (cnta[now] >= 1) {
					cnta[now]--;
					sz--;
					continue;
				}
				if (now % 2) {
					if (now == 1) {
						std::cout << "No" << '\n';
						return;
					}
					q.push(now / 2), q.push(now / 2 + 1);
				} else {
					q.push(now / 2), q.push(now / 2);
				}

				if (q.size() > sz) {
					std::cout << "No" << '\n';
					return;
				}
			}
		}
	}
	for (const auto &[num, cnt] : cnta) {
		if (cnt) {
			std::cout << "No" << '\n';
			return;
		}
	}
	std::cout << "Yes" << '\n';
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