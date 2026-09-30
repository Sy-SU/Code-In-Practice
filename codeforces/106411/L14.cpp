#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string ans = "None";
	std::map<std::string, std::map<int, int>> lo;
	std::map<std::string, int> cnt;
	std::map<int, std::string> tag;
	tag[1] = tag[2] = tag[3] = "None";

	for (int i = 1; i <= n; i++) {
		std::string t;
		int op;
		std::cin >> t >> op;

		lo[t][op]++;
		if (op == 2) {
			if (lo[t][op] == 1 && tag[op] == "None") {
				tag[op] = t;
				cnt[t]++;
				if (ans == "None" && cnt[t] == 2) {
					ans = t;
				} 
			}
		} else {
			if (lo[t][op] == 3 && tag[op] == "None") {
				tag[op] = t;
				cnt[t]++;
				if (ans == "None" && cnt[t] == 2) {
					ans = t;
				}
			}
		}
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