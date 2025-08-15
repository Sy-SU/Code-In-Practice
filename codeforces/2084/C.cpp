#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::map<std::pair<int, int>, int> cnt;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		cnt[{a[i], b[i]}]++, cnt[{b[i], a[i]}]++;
		k += a[i] == b[i];
	}

	if (k > 1) {
		std::cout << -1 << '\n';
		return;
	}

	for (const auto &[p, c] : cnt) {
		if (c % 2) {
			std::cout << -1 << '\n';
			return;
		}
	}

	std::vector<std::pair<int, int>> op;

	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) {
			if (n % 2 == 0) {
				std::cout << -1 << '\n';
				return;
			}

			if (i == (n + 1) / 2) {
				break;
			}

			int j = (n + 1) / 2;
			op.push_back({i, j});

			std::swap(a[i], a[j]), std::swap(b[i], b[j]);
		}
	}

	std::map<std::pair<int, int>, int> pos;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) {
			continue;
		}

		if (pos[{b[i], a[i]}]) {
			if (i != (n + 1 - pos[{b[i], a[i]}])) {
				int j = n + 1 - pos[{b[i], a[i]}];
				op.push_back({i, j});
				std::swap(a[i], a[j]), std::swap(b[i], b[j]);
				i--;
			}
			
		} else {
			pos[{a[i], b[i]}] = ++idx;
		}
	}

	std::cout << op.size() << '\n';
	for (const auto &[x, y] : op) {
		std::cout << x << " " << y << '\n';
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