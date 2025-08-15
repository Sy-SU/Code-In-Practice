#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int a[N];

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int fst = -1, lst = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (fst == -1) {
				fst = i;
			}
			lst = i;
		}
	}

	if (fst == -1 && lst == -1) {
		std::cout << (n + 1) / 2 << '\n';
		return;
	}

	int ans = 0, cnt = 0;
	for (int i = fst; i <= lst; i++) {
		if (a[i] == 1) {
			ans += std::max(0, (cnt - 1) / 2);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	ans += (fst - 1) / 2 + (n - lst) / 2;
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}