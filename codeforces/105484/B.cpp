#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string str;
	std::cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '2') {
			if (i % 2) {
				str[i] = '0' + '1' - str[i];
			}
		}
	}

	std::stack<char> stk;
	for (int i = 0; i < str.size(); i++) {
		if (stk.empty()) {
			stk.push(str[i]);
		} else {
			char tp = stk.top();
			if (str[i] == '0' + '1' - tp) {
				stk.pop();
			} else {
				stk.push(str[i]);
			}
		}
	}

	int cnt[3] = {};

	while (!stk.empty()) {
		cnt[stk.top() - '0']++;
		stk.pop();
	}

	if (cnt[0] > cnt[1]) {
		if (cnt[0] < cnt[1] + cnt[2]) {
			std::cout << str.size() % 2 << '\n';
		} else {
			std::cout << cnt[0] - cnt[1] - cnt[2] << '\n';
		}
	} else {
		if (cnt[1] < cnt[0] + cnt[2]) {
			std::cout << str.size() % 2 << '\n';
		} else {
			std::cout << cnt[1] - cnt[0] - cnt[2] << '\n';
		}
	}

	// 0001212111
	// 0100202010
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