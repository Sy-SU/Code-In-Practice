#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> prime(200005), Nm(200005);
std::vector<int> indp(200005);
int pnum;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> fact(pnum + 1);

	for (int i = 1; i <= n; i++) {
		int num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			while (num % prime[pi] == 0) {
				fact[pi]++;
				num /= prime[pi];
			}
		}

		if (num > 1) {
			fact[indp[num]]++;
		}
	}

	// for (auto [p, c] : fact) {
	// 	std::cerr << "p " << p << " " << c << '\n';
	// }

	i64 ans = 1e18;

	for (int i = 1; i <= n; i++) {
		int num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			int cnt = 0;
			while (num % prime[pi] == 0) {
				num /= prime[pi];
				cnt++;
			}

			// std::cerr << prime[pi] << " " << fact[prime[pi]] << " " << cnt << "\n";
			if (cnt && fact[pi] > cnt) {
				ans = std::min(ans, 0ll);
			}
		}

		if (num > 1) {
			if (fact[indp[num]] > 1) {
				ans = std::min(ans, 0ll);
			}
		}

		num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			while (num % prime[pi] == 0) {
				fact[pi]--;
				num /= prime[pi];
			}
		}

		if (num > 1) {
			fact[indp[num]]--;
		}

		i64 x = 1e9;
		for (int j = 1; j <= pnum; j++) {
			int p = prime[j], c = fact[j];
			if (c == 0) {
				continue;
			}

			i64 m = a[i] % p;
			if (m > 0) {
				x = std::min(x, p - m);
			} else {
				x = 0;
			}
		}

		ans = std::min(ans, b[i] * x);

		num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			while (num % prime[pi] == 0) {
				fact[pi]++;
				num /= prime[pi];
			}
		}
		if (num > 1) {
			fact[indp[num]]++;
		}
	}

	std::map<int, std::vector<std::pair<int, i64>>> have; // have[p] 表示，p 的倍数 有哪些下标？
	for (int i = 1; i <= n; i++) {
		a[i]++;
		int num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			int cnt = 0;
			while (num % prime[pi] == 0) {
				num /= prime[pi];
				cnt++;
			}

			if (cnt > 0) {
				have[prime[pi]].push_back({i, b[i]});
			}
		}

		if (num > 1) {
			have[num].push_back({i, b[i]});
		}
	}

	for (auto &[ind, vec] : have) {
		std::sort(vec.begin(), vec.end(), [](std::pair<int, i64> p1, std::pair<int, i64> p2) {
			return p1.second < p2.second;
		});
	}

	for (int i = 1; i <= n; i++) {
		int num = a[i];
		for (int pi = 1; pi <= pnum && prime[pi] * prime[pi] <= num; pi++) {
			int cnt = 0;
			while (num % prime[pi] == 0) {
				num /= prime[pi];
				cnt++;
			}

			if (cnt > 0) {
				auto &vec = have[prime[pi]];
				for (int j = 0; j < (int)vec.size(); j++) {
					if (vec[j].first == i) {
						continue;
					}
					ans = std::min(ans, b[i] + vec[j].second);
					break;
				}
			}
		}

		if (num > 1) {
			auto &vec = have[num];
			for (int j = 0; j < (int)vec.size(); j++) {
				if (vec[j].first == i) {
					continue;
				}
				ans = std::min(ans, b[i] + vec[j].second);
				break;
			}
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Nm[1] = Nm[0] = 1;
	int pi = 0;
	for (int i = 2; i <= 200000; i++) {
		if (!Nm[i]) {
			prime[++pi] = i;
		}
		for (int pj = 1; prime[pj] * i <= 200000; pj++) {
			Nm[prime[pj] * i] = 1;
			if (i % prime[pj] == 0) {
				break;
			}
		}
	}

	pnum = pi;
	int idx = 0;
	for (int i = 1; i <= pnum; i++) {
		indp[prime[i]] = ++idx;
	}

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}