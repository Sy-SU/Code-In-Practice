#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	s = " " + s;

	std::vector<int> ans(n + 1);
	int cnt = 1e9;
	for (int l = 0; l <= k; l++) {
		int r = k - l;

		std::vector<int> tans(n + 1);

		int cl = 0, cr = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '(' && cl < l) {
				tans[i] = 1;
				cl++;
			}
		}

		for (int i = n; i >= 1; i--) {
			if (s[i] == ')' && cr < r) {
				tans[i] = 1;
				cr++;
			}
		}

		std::string t;
		for (int i = 1; i <= n; i++) {
			if (tans[i]) {
				continue;
			}
			t.push_back(s[i]);
		}

		int tcnt = 0;
		std::stack<char> stk;
		for (auto ch : t) {
			if (ch == '(') {
				stk.push('(');
			} else {
				if (!stk.empty()) {
					tcnt++;
					stk.pop();
				}
			}
		}

		if (tcnt < cnt) {
			cnt = tcnt;
			ans = tans;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}
	std::cout << '\n';
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