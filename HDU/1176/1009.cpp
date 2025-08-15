#include <bits/stdc++.h>

using i64 = long long;

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

	std::vector<int> func(n + 1);
	for (int i = 1; i <= n; i++) {
		func[a[i]] = i;
	}

	func[0] = -1;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (func[b[i - 1]] != func[b[i]] - 1) {
			ans++;
		}
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