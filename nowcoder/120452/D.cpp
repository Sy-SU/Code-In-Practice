#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] != -1;
	}

	std::cout << "The size of the tree is " << cnt << '\n';
	std::cout << "Node " << a[1] << " is the root node of the tree" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}