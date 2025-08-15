#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	std::string s = "red";
	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1]) {
			for (int j = 0; j < 3; j++) {
				if (s[j] != str[i - 1] && s[j] != str[i + 1]) {
					str[i] = s[j];
                    break;
				}
			}
		}
	}
	std::cout << str << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}