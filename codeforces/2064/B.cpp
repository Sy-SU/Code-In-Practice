#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	int ansl = -1, ansr = -1;
	int lst = 1;
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i]] != 1) {
			if (cnt[a[i - 1]] == 1) {
				if (i - 1 - lst + 1 >= ansr - ansl + 1) {
					ansl = lst, ansr = i - 1;
				}
			}	
			lst = i + 1;
			continue;
		}
	}
	if (cnt[a[n]] == 1) {
		if (n - lst + 1 >= ansr - ansl + 1) {
			ansl = lst, ansr = n;
		}
	}
	if (ansl == -1 && ansr == -1) {
		std::cout << 0 << '\n';
	} else {
		std::cout << ansl << " " << ansr << '\n';
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