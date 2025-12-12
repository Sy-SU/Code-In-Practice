#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string s, t;
	std::cin >> s >> t;

	auto calc = [&](std::string str) -> i64 {
		i64 a = 0, b = 0, c = 0;
		for (int i = 0; i + 3 < (int)str.size(); i++) {
			if (str.substr(i, 3) == "hjm") {
				a++;
			}
		}
		for (int i = 0; i + 4 < (int)str.size(); i++) {
			if (str.substr(i, 4) == "nbld") {
				b++;
			}
		}		
		for (int i = 0; i + 4 < (int)str.size(); i++) {
			if (str.substr(i, 4) == "ygnl") {
				c++;
			}
		}
		return a + b * c;
	};

	std::cout << (calc(s) > calc(t) ? "YES" : "NO") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}