#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	if (str.substr(n - 2, 2) == "00") {
		std::cout << "Yes" << '\n';
		return;
	}

	int idx = n;
	for (int i = 0; i < n; i++) {
		if (str[i] == '1') {
			idx = i;
			break;
		}
	}

	str = str.substr(idx, n - idx);
	n = str.size();

	int cnt[2] = {0, 0};
	int l = 0; // 有效的左端点
	for (int i = 0; i < n; i++) {
		cnt[str[i] - '0']++;
		if (cnt[0] > cnt[1]) {
			l = i + 1;
			cnt[0] = cnt[1] = 0;
		}
	}

	std::cout << (n - l >= 4 ? "Yes" : "No") << '\n';
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