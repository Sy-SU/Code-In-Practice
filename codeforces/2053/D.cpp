#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p)
{
	i64 res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p)
{
	return qpow(x, p - 2, p);
}

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<std::pair<i64, int>> a(n + 1, {0, 0}), b(n + 1, {0, 0});	
	for (int i = 1; i <= n; i++) {
		int v;
		std::cin >> v;
		a[i] = {v, i};
	}
	for (int i = 1; i <= n; i++) {
		int v;
		std::cin >> v;
		b[i] = {v, i};
	}

	std::vector<int> funca(n + 1, 0), funcb(n + 1, 0);
	std::vector<int> inva(n + 1, 0), invb(n + 1, 0);
	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	for (int i = 1; i <= n; i++) {
		funca[a[i].second] = i, funcb[b[i].second] = i;
		inva[i] = a[i].second, invb[i] = b[i].second;
		// // std::cerr << a[i].second << "->" << i << '\n';
	}

	i64 ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * std::min(a[i].first, b[i].first) % mod;
	}
	std::cout << ans << " ";

	while (q--) {
		int o, x;
		std::cin >> o >> x; // 实际作用于 func[x]

		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << a[i].first << " \n"[i == n];
		// }
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << b[i].first << " \n"[i == n];
		// }
		// std::cerr << "funca[" << 6 << "] = " << funca[6] << '\n';
		if (o == 1) {
			int ind = funca[x];
			// ind + 1 ~ n 查找第一个严格小于 a[ind].first 的

			int tofind = -1;
			int lo = ind + 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (a[mid].first < a[ind].first + 1) {
					tofind = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			// std::cerr << ind << "->" << x << " " << tofind << '\n';
			// std::cerr << "debug" << a[2].first << " " << ind << " " << tofind << "debug" << '\n';
			if (tofind != -1) {
				i64 pre = std::min(a[ind].first, b[ind].first) * std::min(a[tofind].first, b[tofind].first) % mod;
				ans = ans * inv(pre, mod) % mod;
				// std::cerr << ind << " " << tofind << '\n';
				// funca[]
				a[ind].first++;
				std::swap(a[ind], a[tofind]);
				i64 now = std::min(a[ind].first, b[ind].first) * std::min(a[tofind].first, b[tofind].first) % mod;
				// std::cerr << pre << " " << now << '\n';
				// 这里我们需要找到值为 ind 和 tofind 的 key
				int thekeyofind = inva[ind], thekeyoftofind = inva[tofind];

				std::swap(funca[thekeyofind], funca[thekeyoftofind]);
				std::swap(inva[ind], inva[tofind]);

				ans = ans * now % mod;
			} else {
				i64 pre = std::min(a[ind].first, b[ind].first);
				ans = ans * inv(pre, mod) % mod;
				a[ind].first++;
				i64 now = std::min(a[ind].first, b[ind].first);
				ans = ans * now % mod;
			}

		} else {
			int ind = funcb[x];

			int tofind = -1;
			int lo = ind + 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (b[mid].first < b[ind].first + 1) {
					tofind = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			// std::cerr << ind << " " << tofind << '\n';
			if (tofind != -1) {
				i64 pre = std::min(a[ind].first, b[ind].first) * std::min(a[tofind].first, b[tofind].first) % mod;
				ans = ans * inv(pre, mod) % mod;
				b[ind].first++;
				std::swap(b[ind], b[tofind]);
				i64 now = std::min(a[ind].first, b[ind].first) * std::min(a[tofind].first, b[tofind].first) % mod;
				// std::cerr << pre << " " << now << '\n';
				// std::cerr << "ans = " << ans << '\n';

				int thekeyofind = invb[ind], thekeyoftofind = invb[tofind];

				std::swap(funcb[thekeyofind], funcb[thekeyoftofind]);
				std::swap(invb[ind], invb[tofind]);

				ans = ans * now % mod;
			} else {
				// // std::cerr << "ans = " << ans << '\n';
				i64 pre = std::min(a[ind].first, b[ind].first);
				ans = ans * inv(pre, mod) % mod;
				b[ind].first++;
				i64 now = std::min(a[ind].first, b[ind].first);
				// // std::cerr << pre << " " << now << '\n';
				// // std::cerr << "ans = " << ans << '\n';
				ans = ans * now % mod;
			}
		}
		// std::cerr << "-------------\n";
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << a[i].first << " \n"[i == n];
		// }
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << b[i].first << " \n"[i == n];
		// }
		std::cout << ans << " \n"[q == 0];
		// std::cerr << "\n";
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i].first << " \n"[i == n];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << b[i].first << " \n"[i == n];
	// }

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