#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::vector<i64> ans;

void solve() {
	// i64 k;
	// std::cin >> k;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<i64> vec;
	for (int i = 0; i < 100; i++) {
		vec.push_back(2 * i);
	}

	std::set<i64> s;
	for (int i = 0; i < 100; i++) {
		for (int j = i + 1; j < 100; j++) {
			i64 sum = 0;
			for (int k = i; k <= j; k++) {
				sum += vec[k];
			}
			s.insert(sum);
		}
	}

	for (auto num : s) {
		ans.push_back(num);
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}