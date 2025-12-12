#include <bits/stdc++.h>

using i64 = long long;

constexpr int MAXN = 2e5 + 10;

bool Num[MAXN];
int Prime[MAXN];
int idx[MAXN];

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt;
	cnt.push_back(0);
	for (int i = 1; i <= n; i++) {
		if (Num[i] == 0) {
			cnt.push_back(0);
		}
	}

	int pcnt = cnt.size() - 1;
	// 1 ~ pcnt

	bool equal = 1;
	int g = 0;
	int maxcnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[1]) {
			equal = 0;
		}

		if (g == std::__gcd(g, a[i])) {
			int now = a[i] / g;
			for (int pi = 1; Prime[pi] * Prime[pi] <= now; pi++) {
				bool isok = 0;
				while (now % Prime[pi] == 0) {
					isok = 1;
					now /= Prime[pi];
				}
				if (isok == 0) {
					continue;
				}
				cnt[pi]++;
				maxcnt = std::max(maxcnt, cnt[pi]);
			}
			if (now > 1) {
				cnt[idx[now]]++;
				maxcnt = std::max(maxcnt, cnt[idx[now]]);
			}
		} else {
			g = std::__gcd(g, a[i]);
			for (int j = 1; j <= pcnt; j++) {
				cnt[j] = 0;
			}
			maxcnt = 0;
			for (int j = 1; j <= i; j++) {
				int now = a[j] / g;
				for (int pi = 1; Prime[pi] * Prime[pi] <= now; pi++) {
					bool isok = 0;
					while (now % Prime[pi] == 0) {
						isok = 1;
						now /= Prime[pi];
					}
					if (isok == 0) {
						continue;
					}
					cnt[pi]++;
					maxcnt = std::max(maxcnt, cnt[pi]);
				}
				if (now > 1) {
					cnt[idx[now]]++;
					maxcnt = std::max(maxcnt, cnt[idx[now]]);
				}
			}
		}

		if (equal) {
			std::cout << 0 << " ";
		} else {
			std::cout << maxcnt << " ";
		}
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Num[1] = Num[0] = 1;
	int p_index = 0;
	for (int i = 2; i <= 200000; i++) {
		if (!Num[i]) {
			Prime[++p_index] = i;
			idx[i] = p_index;
		}
		for (int pj = 1; Prime[pj] * i <= 200000; pj++) {
			Num[Prime[pj] * i] = 1;
			if (i % Prime[pj] == 0) {
				break;
			}
		}
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}