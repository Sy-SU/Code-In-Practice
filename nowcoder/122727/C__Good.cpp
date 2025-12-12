#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> sta(n + 1, -1);
	for (int i = 1; i <= m; i++) {
		int x, t;
		std::cin >> t >> x;

		sta[t] = 1 - x;
	}

	std::vector<int> ans(n + 1);
	for (int ss = 0; ss < (1 << n); ss++) {
		int nows = ss;
		bool isok = 1;
		int at = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int ch = nows % 2;
			nows /= 2;

			at ^= ch;
			if (sta[i] != -1 && sta[i] != at) {
				isok = 0;
			}

			cnt += ch;
		}
		if (isok) {
			ans[cnt] = 1;
		}
	}

	int tt;
	std::cin >> tt;

	while (tt--) {
		int s;
		std::cin >> s;

		std::cout << (ans[s] ? "Yes" : "No") << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}