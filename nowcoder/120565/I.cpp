#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

void solve() {
	int n, m;
	i64 h;
	std::cin >> n >> m >> h;

	std::vector<std::pair<int, i64>> op(m + 1);
	for (int i = 1; i <= m; i++) {
		int p;
		i64 f;
		std::cin >> p >> f;

		op[i] = {p, f};
	} 

	int ans = -1;
	int lo = 1, hi = m;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int maxt) -> bool {
			std::vector<i64> del(n + 4);
			std::vector<i64> deldel(n + 4);
			// SegmentTree<Info, Tag> sgt(help);
			// DoubleFenwick<i64> fenwick(help);
			for (int t = 1; t <= maxt; t++) {
				auto [p, f] = op[t];

				int l1 = std::max(1ll, p - f + 1), r1 = p;
				// fenwick.add(l1 + 1, l1 + 1, f - r1 + l1);
				// fenwick.add(l1 + 1 + 1, r1 + 1, 1);
				// fenwick.add(r1 + 1 + 1, r1 + 1 + 1, -f);
				deldel[l1] += f - r1 + l1, deldel[l1 + 1] -= f - r1 + l1;
				deldel[l1 + 1] += 1, deldel[r1 + 1] -= 1;
				deldel[r1 + 1] += -f, deldel[r1 + 1 + 1] -= -f;

				int l2 = p + 1, r2 = std::min(n * 1ll, p + f - 1);
				if (l2 <= r2) {	
					// fenwick.add(l2 + 1, l2 + 1, f - 1);
					// fenwick.add(l2 + 1 + 1, r2 + 1, -1);
					// fenwick.add(r2 + 1 + 1, r2 + 1 + 1, -(f - 1 + l2 - r2));
					deldel[l2] += f - 1, deldel[l2 + 1] -= f - 1;
					deldel[l2 + 1] += -1, deldel[r2 + 1] -= -1;
					deldel[r2 + 1] += -(f - 1 + l2 - r2), deldel[r2 + 1 + 1] -= -(f - 1 + l2 - r2);
				}
			}

			i64 val = 0, maxv = -INF;
			// std::cerr << "t = " << maxt << '\n';
			for (int i = 1; i <= n; i++) {
				del[i] = del[i - 1] + deldel[i];
			}
			for (int i = 1; i <= n; i++) {
				// val += fenwick.sum(i + 1, i + 1);
				val += del[i];
				maxv = std::max(maxv, val);
				// std::cerr << val << " ";
			}
			// std::cerr << '\n';
			return maxv > h;
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	if (ans == -1) {
		std::cout << "No" << '\n';
	} else {
		std::cout << "Yes" << '\n';
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}