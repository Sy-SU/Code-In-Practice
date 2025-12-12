#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> limit(n + 1), cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		limit[a[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (limit[i] % k) {
			std::cout << 0 << '\n';
			return;
		}
		limit[i] /= k;
	}

	i64 ans = 0;
	int ptr = 1;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		while (ptr <= i && cnt[a[i]] > limit[a[i]]) {
			cnt[a[ptr]]--;
			ptr++;
		}

		ans += (i - ptr + 1);
	}

	std::cout << ans << '\n';
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