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

	bool isok = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] <= a[i - 1]) {
			isok = 0;
			break;
		}
	}
	if (isok) {
		std::cout << 0 << '\n';
		return;
	}

	int lst = n + (a[n] < n);
	for (int i = n - 1; i >= 1; i--) {
		if (i <= a[i] && a[i] < a[i + 1]) {
			lst = i;
		} else {
			break;
		}
	}

	std::map<int, int> max;
	for (int i = 1; i <= n; i++) {
		max[a[i]] = i;
	}

	std::map<int, int> cnt;
	for (int i = 1; i < lst; i++) {
		if (i != a[i] && cnt[a[i]] == 0) {
			cnt[a[i]] = 1;
			lst = std::max(lst, max[a[i]]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[a[i]]) {
			a[i] = i;
		}
	}

	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i + 1]) {
			for (int j = 1; j <= n; j++) {
				std::cout << a[j] << " \n"[j == n];
			}
			exit(-1);
		}
	}

	int ans = 0;
	for (auto [_, __] : cnt) {
		ans += __ == 1;
	}
	std::cout << ans << '\n';
	// assert(cnt.size() == cnt.count(1));
	// std::cout << cnt.size() << '\n';
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