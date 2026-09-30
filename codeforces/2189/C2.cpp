#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);

	if (n % 2) {
		p[n] = 1;
		for (int i = 2; i < n; i++) {
			p[i] = i ^ 1;
		}

		std::vector<int> vis(n + 1);
		for (int i = 2; i <= n; i++) {
			vis[p[i]] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				p[1] = i;
			}
		}
	} else {
		int fact = 1;
		while (n % (fact * 2) == 0) {
			fact *= 2;
		}

		if (fact == n) {
			std::cout << -1 << '\n';
			return;
		}

		p[n] = 1;
		p[fact] = n, p[fact + 1] = fact;
		p[1] = fact + 1;

		for (int i = 2; i < n; i++) {
			if (p[i]) {
				continue;
			}
			p[i] = i ^ 1;
		}
	}
	

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << (p[i] ^ i) << " \n"[i == n];
	// }

	// std::vector<int> vis(n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	vis[p[i]]++;
	// }
	// for (int i = 1; i <= n; i++) {
	// 	assert(vis[i] == 1);
	// }

	// bool isok = 1;
	// for (int i = 1; i < n; i++) {
	// 	bool ps = 0;
	// 	for (int j = i; j <= n; j++) {
	// 		if (p[i] == (p[j] ^ i)) {
	// 			ps = 1;
	// 			break;
	// 		}
	// 	}
	// 	if (ps == 0) {
	// 		isok = 0;
	// 		break;
	// 	}
	// }

	// if (isok) {
	// 	std::cerr << "passed" << '\n';
	// 	// return;
	// } else {
	// 	std::cerr << "failed" << '\n';
	// 	std::cerr << "n = " << n << '\n';
	// 	assert(0);
	// }

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << (p[i] ^ i) << " \n"[i == n];
	// }
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