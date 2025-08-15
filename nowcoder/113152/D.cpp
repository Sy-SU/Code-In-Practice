#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	auto printer = [&](auto &&self, int sum, int lst, std::vector<int> arr) -> void {
		if (sum == 0) {
			for (auto num : arr) {
				std::cout << num << ' ';
			}
			std::cout << '\n';
			return;
		}
		for (int i = 1; i <= sum; i++) {
			if (i == lst) {
				continue;
			}
			std::vector<int> narr = arr;
			narr.push_back(i);
			self(self, sum - i, i, narr);
		}
	};

	std::vector<int> arr;
	printer(printer, n, -1, arr);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}