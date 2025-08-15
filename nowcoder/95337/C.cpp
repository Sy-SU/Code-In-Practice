#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;

	std::string a, b, c;
	std::cin >> a >> b >> c;

	int cnt[4] = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		if (c[i] == (a[i] == b[i] ? '0' : '1')) {
			continue;
		}
		cnt[0] += (a[i] == '0' && b[i] == '0');
		cnt[1] += (a[i] == '0' && b[i] == '1');
		cnt[2] += (a[i] == '1' && b[i] == '0');
		cnt[3] += (a[i] == '1' && b[i] == '1');
	}

	i64 ans = (cnt[0] + cnt[1] + cnt[2] + cnt[3]) * x;
	std::sort(cnt, cnt + 4);

	if (cnt[3] > cnt[0] + cnt[1] + cnt[2]) {
		ans = std::min(ans, (cnt[0] + cnt[1] + cnt[2]) * y + (cnt[3] - cnt[0] - cnt[1] - cnt[2]) * x);
	} else {
		ans = std::min(ans, (cnt[0] + cnt[1] + cnt[2] + cnt[3]) / 2 * y + (cnt[0] + cnt[1] + cnt[2] + cnt[3]) % 2 * x);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}