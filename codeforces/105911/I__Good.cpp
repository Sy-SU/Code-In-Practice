#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

int C(int n, int m) {
	int res = 1;
	for (int i = n; i >= n - m + 1; i--) res *= i;
	for (int i = 1; i <= m; i++) res /= i;

	return res;
}

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	str = "1" + str;

	int ans = 0;

	std::vector<int> pos1;
	for (int i = 0; i <= n; i++) {
		if (str[i] == '1') {
			pos1.push_back(i);
		}
	}

	int sz = pos1.size();

	if (sz <= k) {
		std::cout << 0 << '\n';
		return;
	}

	{
		int r = k + 1;
		int l = r - k - 1;
		int lo = pos1[l] + 1, hi = pos1[r] - 1;

		ans += C(hi - lo + 1, k);
	}

	for (int r = k + 1; r < sz; r++) {
		int l = r - k;
		int lo = pos1[l] + 1, hi = pos1[r] - 1;

		ans += C(hi - lo + 1, k);
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