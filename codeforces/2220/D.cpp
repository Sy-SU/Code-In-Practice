#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> anspre(2 * n + 2, -1);
	std::vector<int> anssuf(2 * n + 2, -1);

	int lo = 1, hi = 2 * n + 1, fd1 = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {
			if (x == 2 * n + 1) {
				return 1;
			}

			int res1;
			if (anspre[x] != -1) {
				res1 = anspre[x];
			} else {
				std::cout << "? " << x << " ";
				for (int i = 1; i <= x; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;		
				
				std::cin >> res1;
				anspre[x] = res1;
			}

			int res2;
			if (anssuf[x + 1] != -1) {
				res2 = anssuf[x + 1];
			} else {
				std::cout << "? " << 2 * n + 1 - x << " ";
				for (int i = x + 1; i <= 2 * n + 1; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;

				std::cin >> res2;
				anssuf[x + 1] = res2;	
			}

			if (res1 == res2 && x % 2 != res1 % 2) {
				return 1;
			} else {
				return 0;
			}
		};

		if (check(mid)) {
			hi = mid - 1;
			fd1 = mid;
		} else {
			lo = mid + 1;
		}
	}

	// std::cerr << "the last " << fd1 << std::endl;

	lo = 1, hi = 2 * n + 1;
	int fd2 = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {
			if (x == 1) {
				return 1;
			}

			int res1;
			if (anspre[x - 1] != -1) {
				res1 = anspre[x - 1];
			} else {
				std::cout << "? " << x - 1 << " ";
				for (int i = 1; i <= x - 1; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;	
				
				std::cin >> res1;
				anspre[x - 1] = res1;
			}
			
			int res2;
			if (anssuf[x] != -1) {
				res2 = anssuf[x];
			} else {
				std::cout << "? " << 2 * n + 2 - x << " ";
				for (int i = x; i <= 2 * n + 1; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;

				std::cin >> res2;
				anssuf[x] = res2;
			}

			if (res1 == res2 && (2 * n + 2 - x) % 2 != res2 % 2) {
				return 1;
			} else {
				return 0;
			}
		};

		if (check(mid)) {
			lo = mid + 1;
			fd2 = mid;
		} else {
			hi = mid - 1;
		}
	}

	// std::cerr << "the first " << fd2 << std::endl;

	lo = fd2 + 1, hi = fd1 - 1;
	int fd3 = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int x) -> bool {
			int res1;
			if (anspre[x] != -1) {
				res1 = anspre[x];
			} else {
				std::cout << "? " << x << " ";
				for (int i = 1; i <= x; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;		
				
				std::cin >> res1;
				anspre[x] = res1;
			}

			int res2;
			if (anssuf[x + 1] != -1) {
				res2 = anssuf[x + 1];
			} else {
				std::cout << "? " << 2 * n + 1 - x << " ";
				for (int i = x + 1; i <= 2 * n + 1; i++) {
					std::cout << i << " ";
				}
				std::cout << std::endl;

				std::cin >> res2;
				anssuf[x + 1] = res2;

			}

			if (res1 < res2) {
				return 1;
			} else {
				return 0;
			}
		};

		if (check(mid)) {
			hi = mid - 1;
			fd3 = mid;
		} else {
			lo = mid + 1;
		}
	}

	std::cout << "! " << fd2 << " " << fd3 << " " << fd1 << std::endl;
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