#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;

	int p = 1;
	for (int i = 1; i <= 9; i++) {
		if (p > n / 10) {
			break;
		}
		p *= 10;
	}

	std::vector<int> out;
	bool isok = 0;
	for (int i = 1; i <= q; i++) {
		int res = n % 10, del = n / 10;
		res *= res;
		res %= 10;
		n += p * res;
		out.push_back(n);
		if (n == m) {
			isok = 1;
			break;
		}
	}
	if (isok) {
		for (const auto& num : out) {
			std::cout << num << '\n';
		}
	} else {
		std::cout << -1 << '\n';
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}