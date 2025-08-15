#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int pre[30][N];

int check(std::string str) {
	str = " " + str;
	int n = str.size() - 1;

	for (int i = 1; i <= n; i++) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			pre[ch - 'a'][i] = pre[ch - 'a'][i - 1] + (ch == str[i]);
		}
	}

	int lo = 2, hi = n - 1;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			for (int i = 1; i + mid - 1 <= n; i++) {
				if (pre[str[i] - 'a'][i - 1] - pre[str[i] - 'a'][0] != 0) {
					return 1;
				}
				if (pre[str[i + mid - 1] - 'a'][n] - pre[str[i + mid - 1] - 'a'][i + mid - 1] != 0) {
					return 1;
				}
			}
			return 0;
		};

		if (check()) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	return ans;
}

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
	return rnd() % (r - l + 1) + l;
}


void solve() {
	int n, m;
	// std::cin >> n >> m;

	n = rng(3, 100);
	m = rng(3, n);

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
				ans[i] = 'a' + i - 1;
			}
		}
		std::cout << "YES" << '\n';
		std::cout << ans << '\n';
		if (m != check(ans)) {
			std::cerr << "WA1 : " << "n = " << n << " m = " << m << '\n';
			system("pause");
		}
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
	 		if (m != check(ans)) {
				std::cerr << "WA2 : " << "n = " << n << " m = " << m << '\n';
				system("pause");
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
			if (m != check(ans)) {
				std::cerr << "WA3 : " << "n = " << n << " m = " << m << '\n';
				system("pause");
			}
 		}
		
	} else {
		std::string ans(n, 'z');
		char ch = 'a';
		for (int i = n - 2; i >= m; i--) {
			ans[i + 1] = ans[n - 2 - i] = ch;
			ch++;
		}
		std::cout << "YES" << '\n';
		std::cout << ans << '\n';
		if (m != check(ans)) {
			std::cerr << "WA4 : " << "n = " << n << " m = " << m << '\n';
			system("pause");
		}
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