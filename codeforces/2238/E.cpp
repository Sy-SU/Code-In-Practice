#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int T, F, N;
};

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	s = " " + s;

	std::vector<Node> pre(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		if (s[i] == 'T') {
			pre[i].T++;
		} else if (s[i] == 'F') {
			pre[i].F++;
		} else if (s[i] == 'N') {
			pre[i].N++;
		}
	}

	auto query = [&](int l, int r) -> Node {
		Node res;
		res.T = pre[r].T - pre[l - 1].T;
		res.F = pre[r].F - pre[l - 1].F;
		res.N = pre[r].N - pre[l - 1].N;

		return res;
	};

	std::vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		
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