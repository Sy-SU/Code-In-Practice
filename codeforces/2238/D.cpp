#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;

	std::map<int, int> cnt;
	int num = n;
	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			cnt[i]++;
		}
	}
	if (num > 1) {
		cnt[num]++;
	}

	// for (auto [x, y] : cnt) {std::cerr << x << "^" << y << ' ';}std::cerr << '\n';

	i64 ans = 0, sum = 0;
	for (auto [x, y] : cnt) {
		sum += y;
		ans++;
	}

	sum--;
	std::cout << ans + sum << '\n';
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