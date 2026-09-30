#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}

	i64 ans = n;

	auto work = [&](std::vector<int> &up, std::vector<int> &down) -> void {
		std::vector<int> ok(n, 1);
		for (int i = 0; i < n; i++) {
			// up[i]
			std::vector<int> now(n);
			for (int j = 0; j < n; j++) {
				if (down[j] > up[i]) {
					int d = (j - i + n) % n;
					now[d] = 1;
				}
			}
			for (int j = 0; j < n; j++) {
				ok[j] &= now[j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += ok[i];
		}
		ans *= cnt;
	};

	work(a, b), work(b, c);

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