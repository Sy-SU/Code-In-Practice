#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> pre(n + 1);
	i64 ans = 0;
	std::map<int, int> cnt;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		char c;
		std::cin >> c;

		if (c == 'B') {
			pre[i] = pre[i - 1] + 1;
		} else {
			pre[i] = pre[i - 1] - 1;
		}
		ans += cnt[pre[i]];
		cnt[pre[i]]++;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}