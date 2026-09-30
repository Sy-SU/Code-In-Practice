#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int sz = (1 << n);
	std::vector<int> a(sz);
	for (int i = 0; i < sz; i++) {
		a[i] = i;
	}

	int min = 1e9;

	do {
		int ans = 0;
		for (int i = 1; i < (1 << n); i++) {
			ans += (a[i - 1] ^ a[i]);
		}
		// std::cout << ans << '\n';
		// for (int i = 0; i < sz; i++) {
		// 	std::cout << a[i] << " ";
		// }
		// std::cout << '\n';

		min = std::min(min, ans);
	} while (std::next_permutation(a.begin(), a.end()));

	std::cout << "min " << min << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}