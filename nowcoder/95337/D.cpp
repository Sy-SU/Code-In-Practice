#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	str = " " + str;

	std::vector<int> pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + (str[i] == '1');
	}

	int ans = 0;
	for (int k = 1; k <= n; k++) {
		int tmp = 1;
		for (int i = 1; i <= n; i += k) {
			int l = i, r = std::min(n, i + k - 1);
			tmp += ((pre[r] - pre[l - 1]) < (r - l + 1) && (pre[r] - pre[l - 1]) > 0);
		}
		ans ^= tmp;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}