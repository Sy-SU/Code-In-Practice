#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	if (m == n || m == 1 || m < n - 26) {
		std::cout << "NO" << '\n';
		return;
	}

	if (n <= 27) {
		std::string ans(n, 'z');
		if (m == 0) {
			for (int i = 1; i < n - 1; i++) {
				ans[i] = 'a' + i - 1;
			}
		} else {
			for (int i = 0; i < m - 1; i++) {
				ans[i] = 'a' + i;
			}
			ans[m - 1] = 'a' + n - 2;
			for (int i = m; i < n; i++) {
				ans[i]=  'a' + i - 1;
			}
		}
		std::cout << "YES" << '\n';
		std::cout << ans << '\n';
 	} else if (n <= 52) {
 		if (m <= 26) {
 			std::string ans;
	 		for (int i = 0; i < n - m; i++) {
	 			char ch = 'a' + i;
	 			ans.push_back(ch);
	 		}

	 		for (int i = 0; i < m; i++) {
	 			char ch = 'a' + i;
	 			ans.push_back(ch);
	 		}
	 		
	 		std::cout << "YES" << '\n';
	 		std::cout << ans << '\n';
 		} else {
 			std::string ans(n, 'z');
			char ch = 'a';
			for (int i = n - 2; i >= m; i--) {
				ans[i + 1] = ans[n - 2 - i] = ch;
				if (ch > 'z') {
					std::cout << "NO" << '\n';
					return;
				}
				ch++;
			}
			std::cout << "YES" << '\n';
			std::cout << ans << '\n';
 		}
 		
	} else {
		std::string ans(n, 'z');
		char ch = 'a';
		for (int i = n - 2; i >= m; i--) {
			ans[i + 1] = ans[n - 2 - i] = ch;
			if (ch > 'z') {
				std::cout << "NO" << '\n';
				return;
			}
			ch++;
		}
		std::cout << "YES" << '\n';
		std::cout << ans << '\n';
	}
	
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