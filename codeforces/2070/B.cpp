#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, x;
	i64 k;
	std::cin >> n >> x >> k;

	std::string str;
	std::cin >> str;

	int ptr = -1;
	int now = x;
	for (int i = 0; i < n; i++) {
		now += (str[i] == 'R' ? 1 : -1);
		if (now == 0) {
			ptr = i;
			// 0 ~ ptr
			break;
		}
	}
	if (ptr == -1) {
		std::cout << 0 << '\n';
		return;
	}
	k -= (ptr + 1);

	ptr = -1;
	for (int i = 0; i < n; i++) {
		now += (str[i] == 'R' ? 1 : -1);
		if (now == 0) {
			ptr = i;
			// 0 ~ ptr
			break;
		}
	}

	if (ptr == -1) {
		std::cout << 1 << '\n';
		return;
	}

	std::cout << 1 + k / (ptr + 1) << '\n';
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