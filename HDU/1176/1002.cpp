#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	i64 del, res;
};

void solve() {
	int n, p;
	i64 k, m;
	std::cin >> n >> m >> k >> p;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<NODE> node(n + 1);
	for (int i = 1; i <= n; i++) {
		node[i] = {a[i] / k, a[i] % k};
	}

	std::sort(node.begin() + 1, node.end(), [](NODE n1, NODE n2) {
		return n1.del > n2.del;
	});

	i64 lo = 1, hi = m, ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 x) -> bool {
			i64 adddel = 0; // 多余的 del block
			i64 get = 0;

			std::vector<i64> rv;
			for (int i = 1; i <= p; i++) {
				get += std::min(x, node[i].del) * k;
				adddel += std::max(0ll, x - node[i].del);
				if (x > node[i].del) {
					rv.push_back(node[i].res);
				}
			}
			for (int i = p + 1; i <= n; i++) {
				get += std::min(adddel, node[i].del) * k;
				assert(x >= std::min(adddel, node[i].del));
				if (x > std::min(adddel, node[i].del)) {
					rv.push_back(node[i].res);
				}
				adddel -= std::min(adddel, node[i].del);
			}

			std::sort(rv.begin(), rv.end(), std::greater<i64>());

			for (int i = 0; i < std::min((i64)rv.size(), adddel); i++) {
				get += rv[i];
			}

			return get >= m;
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
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