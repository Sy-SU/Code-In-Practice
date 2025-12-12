#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int f1 = -1;
	for (int i = 0; i < n; i++) {
		if (str[i] == '1') {
			f1 = i;
			break;
		}
	}

	int lst = 0, maxlen = 0;
	for (int i = f1 + 1; i < n; i++) {
		if (str[i] == '0') {
			lst++;
		} else {
			maxlen = std::max(maxlen, lst);
			// std::cerr << "len = " << lst << '\n';
			lst = 0;
		}
	}

	// std::cerr << "len = " << lst + f1 << '\n';
	maxlen = std::max(maxlen, lst + f1);

	std::cout << maxlen << '\n';
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