#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> x(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i];
	}

	auto ask = [&](int i, int j, int &ans) -> void {
		std::cout << "? " << i << " " << j << std::endl;
		std::cin >> ans;
	};

	auto speak = [&](char ch) -> void {
		std::cout << "! " << ch << std::endl;
	};

	std::vector<int> cnt(n + 1);

	for (int i = 1; i <= n; i++) {
		cnt[x[i]]++;
	}

	int a = -1, b = -1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			a = i;
		} else {
			b = i;
		}
	}

	int node1 = -1, noden = -1;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			node1 = i;
		}
		if (x[i] == n) {
			noden = i;
		}
	}

	if (a == -1) {
		int res = -1;
		ask(node1, noden, res);
		if (res == -1) {
			return;
		} else if (res < n - 1) {
			speak('A');
			return;
		} else if (res > n - 1) {
			speak('B');
			return;
		}
		ask(noden, node1, res);
		if (res == -1) {
			return;
		} else if (res <= 1) {
			speak('A');
			return;
		} else {
			assert(res == n - 1);
			speak('B');
		}
	} else {
		int res = -1;
		ask(a, b, res);
		if (res == -1) {
			return;
		} else if (res == 0) {
			speak('A');
		} else {
			speak('B');
		}
	}


}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}