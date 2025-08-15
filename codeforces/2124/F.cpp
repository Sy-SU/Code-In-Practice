#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

struct NODE {
	int l, r, sta;
	bool operator < (NODE n2) const {
		if (l == n2.l) {
			if (r == n2.r) {
				return sta < n2.sta;
			} else {
				return r < n2.r;
			}
		} else {
			return l < n2.l;
		}
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::set<int>> nt(n + 1);
	for (int i = 1; i <= m; i++) {
		int p, x;
		std::cin >> p >> x;

		nt[p].insert(x);
	}

	std::map<NODE, int> valid;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int len = j - i + 1;
			std::vector<int> tmp(n + 1);
			for (int sta = 1; sta <= len; sta++) {
				for (int pos = i; pos <= j; pos++) {
					tmp[pos] = (sta + (pos - i) - 1) % len + 1;
				}
				bool isok = 1;
				for (int pos = i; pos <= j; pos++) {
					if (nt[pos].find(tmp[pos]) != nt[pos].end()) {
						isok = 0;
						break;
					}
				}
				valid[{i, j, sta}] = isok;
			}
		}
	}

	std::vector<i64> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			// j + 1 ~ i
			int len = i - j;
			i64 cnt = 0;
			for (int sta = 1; sta <= len; sta++) {
				if (valid[{j + 1, i, sta}] == 0) {
					continue;
				}
				std::cerr << i << "<-" << j << '\n';
				std::cerr <<  j + 1 - (sta - 1) << " " << j + 1 - (sta - 1) + i - j - 1 << '\n';
				if (valid[{j + 1 - (sta - 1), j + 1 - (sta - 1) + i - j - 1, 1}]) {
					continue;
				}
				cnt++;
			}
			dp[i] = (dp[i] + cnt * dp[j] % mod) % mod;

		}
	}

	for (int i = 1; i <= n; i++) std::cerr << dp[i] << " \n"[i == n];

	std::cout << dp[n] << '\n';
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