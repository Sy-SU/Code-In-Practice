#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int a[N], b[N];

void solve() {
	for (int i = 1; i <= 15; i++) {
		int p, q;
		scanf("%d-%d", &p, &q);
		a[16 - i] = p, b[16 - i] = q;
	}
	int now = 1;
	while (now <= 15) {
		if (a[now] > b[now]) {
			now = 2 * now + 1;
		} else {
			now = 2 * now;
		}
	}
	// 31 - A 16 - P
	std::cout << (char)('P' - (now - 16)) << '\n';
}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	solve();

	return 0;
}