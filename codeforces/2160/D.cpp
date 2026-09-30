#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	// input
	// std::vector<int> a(2 * n + 1);
	// for (int i = 1; i <= 2 * n; i++) {
	// 	std::cin >> a[i];
	// }

	// auto find = [&](std::vector<int> q) -> int {
	// 	int ans = 0;
	// 	std::map<int, int> cnt;
	// 	for (auto ind : q) {
	// 		cnt[a[ind]]++;
	// 	}

	// 	for (auto [v, t] : cnt) {
	// 		if (t >= 2) {
	// 			ans = v;
	// 		}
	// 	}
	// 	return ans;
	// };

	auto query = [&](int k, std::vector<int> q) -> int {
		std::cout << "? " << k << " ";
		for (auto num : q) {
			std::cout << num << " ";
		}
		std::cout << std::endl;

		int res;
		// res = find(q);
		// std::cout << "response " << res << std::endl; 
		std::cin >> res;
		return res;
	};

	std::vector<int> ans(2 * n + 1, -1);

	std::vector<int> ask;
	ask.push_back(1);
	for (int r = 2; r <= 2 * n; r++) {
		ask.push_back(r);
		int res = query(ask.size(), ask);
		if (res) {
			ask.pop_back();
			ans[r] = res;
		}
	}

	ask.clear();

	for (int i = 1; i <= 2 * n; i++) {
		if (ans[i] != -1) {
			ask.push_back(i);
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (ans[i] != -1) {
			continue;
		}
		ask.push_back(i);
		int res = query(ask.size(), ask);
		assert(res != 0);
		ans[i] = res;
		ask.pop_back();
	}

	std::cout << "! ";
	for (int i = 1; i <= 2 * n; i++) {
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
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