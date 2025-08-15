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
	int maxb = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		maxb = std::max(maxb, b[i]);
	}

	std::set<int> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] >= b[j]) {
				s.insert(a[i] - b[j]);
			}
		}
	}

	std::set<int> ok;
	for (const auto &num : s) {
		for (int i = 1; i * i <= num; i++) {
			if (num % i) {
				continue;
			}
			if (i > maxb) {
				ok.insert(i);
			}
			if (num / i > maxb) {
				ok.insert(i);
			}
		}
	}

	for (const auto &num : ok) {
		std::vector<int> cnta()
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