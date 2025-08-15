#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE {
	int l, r, i;
	bool operator!=(const NODE& o) const {
        return l != o.l || r != o.r || i != o.i;
    }
    bool operator==(const NODE& o) const {
        return l == o.l && r == o.r && i == o.i;
    }
};

int t = 1, testcase = 0;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> str(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> str[i];
		str[i] = " " + str[i];
	}

	std::unordered_map<std::string, NODE> func;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			std::string t = str[i].substr(j - 1, 2);
			func[t] = {j - 1, j, i};
		}
		for (int j = 3; j <= m; j++) {
			std::string t = str[i].substr(j - 2, 3);
			func[t] = {j - 2, j, i};
		}
	}

	std::string s;
	std::cin >> s;
	s = " " + s;
	NODE e = {-1, -1, -1};
	std::vector<std::vector<NODE>> dp(m + 1);
	dp[0].push_back(e);
	for (int i = 2; i <= m; i++) {
		// std::cerr << i << "\n";
		if (i >= 3) {
			std::string t = s.substr(i - 2, 3);
			if (func.count(t) && !dp[i - 3].empty() && dp[i - 3][0] == e) {
				dp[i] = dp[i - 3];
				dp[i].emplace_back(func[t]);
			}
		}
		std::string t = s.substr(i - 1, 2);
		if (func.count(t) && !dp[i - 2].empty() && dp[i - 2][0] == e) {
			dp[i] = dp[i - 2];
			dp[i].emplace_back(func[t]);
		}
	}
	// std::cerr << "ok" << '\n';
	if (dp[m].empty() || dp[m][0] != e) {
		std::cout << -1 << '\n';
	} else {
		std::cout<< (int)dp[m].size() - 1 << '\n';
		for (int i = 1; i < dp[m].size(); i++) {
			auto [l, r, x] = dp[m][i];
			std::cout << l << " " << r << " " << x << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}