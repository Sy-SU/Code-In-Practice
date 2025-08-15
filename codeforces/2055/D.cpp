#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k, l;
	std::cin >> n >> k >> l;
	k *= 2, l *= 2;

	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] *= 2;
	}

	i64 now = k, maxt = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] > now) {
			a[i] = std::max(now, a[i] - maxt);
			maxt += (a[i] - now) / 2;
			now = (now + a[i]) / 2 + k;
		} else {
			a[i] = std::min(now, a[i] + maxt);
			now = a[i] + k;
		}
	}
	if (now <= l) {
		maxt += l - now;
	}
	std::cout << maxt << '\n';
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