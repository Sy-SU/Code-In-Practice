#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p) {
	return qpow(x, p - 2, p);
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> pos(n + 2, std::vector<i64>(n + 1));
	// pos[i] 表示最后取了 i 之后，每个数出现次数的期望

	bool modified = 0;
	std::vector<int> vis(n + 1);

	int num = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			num++;
			if (modified == 0) {
				pos[n + 1][a[i]] += 1;
			} else {
				for (int j = 1; j <= n; j++) {
					if (vis[j]) {
						continue;
					}
					pos[j][a[j]] += 1;
				}
			}
		} else {
			if (modified == 0) {
				for (int lst = 1; lst <= n; lst++) {
					// 最后取出 lst
					if (pos[n + 1][lst]) {
						vis[lst] = 1;
						for (int j = 1; j <= n; j++) {
							pos[lst][j] = pos[n + 1][j];
							if (j == lst) {
								pos[lst][j] -= 1;
							}
						}
					}
				}
				modified = 1;
			} else {
				for (int lst = 1; lst <= n; lst++) {
					for (int j = 1; j <= n; j++) {
						if (pos[lst][j]) {
							pos[lst][j]
						}
					}
				}
			}
			
			num--;
		}
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