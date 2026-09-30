#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

void solve() {
	int n;
	std::cin >> n;

	std::map<i64, i64> cnt;
	for (int i = 1; i <= n; i++) {
		i64 c, w;
		std::cin >> c >> w;

		cnt[w] += c;
	}

	i64 ans = 0;

	i64 rest = -1;
	for (auto it = cnt.begin(); it != cnt.end(); ) {
		auto [w, c] = *it;
		if (c == 0) {
			it = cnt.erase(it);
			continue;
		}
		if (rest > 0) {
			// w, rest
			c--;
			cnt[w + rest]++;
			ans += w + rest;
			ans %= mod;
			rest = -1;
		}
		i64 d = c / 2;
		if (c % 2) {
			rest = w;
		}

		cnt[w * 2] += d;
		ans += w % mod * d * 2;
		ans %= mod;

		it = cnt.erase(it);
		// it++;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}