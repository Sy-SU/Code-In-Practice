#include <bits/stdc++.h>

using i64 = long long;

int n, ok;
int cnt = 0;

bool done;

int ask(int x) {
	cnt++;
	// assert(cnt <= 2 * n - 2);
	std::cout << "? " << x << std::endl;
	int res;
	std::cin >> res;

	return (res ^ x);
}

void solve() {
	std::cin >> n;

	ok = 0;
	done = 0;

	int max = ask(0), min = ask((1 << 30) - 1);
	// std::cerr << "max = " << max << " min = " << min << '\n';

	std::map<int, int> ans, vis;
	ans[max] = 1, ans[min] = 1;
	vis[0] = max + 1, vis[(1 << 30) - 1] = min + 1;
	ok += 2;


	auto work = [&](auto &&self, int l, int r) -> void {
		if (l == r) {
			return;
		}
		for (int b = 29; b >= 0; b--) {
			if (((l >> b) & 1) != ((r >> b) & 1)) {
				if (b == 0) {
					break;
				}
				int ask1 = (1 << b), ask2 = (1 << b) - 1;
				for (int i = b + 1; i <= 29; i++) {
					int tb = (l >> i) & 1;
					tb ^= 1;
					ask1  += (tb << i), ask2 += (tb << i);
				}
				int res1 = vis[ask1] - 1;
				if (vis[ask1] == 0) {
					res1 = ask(ask1);
					vis[ask1] = res1 + 1;
				}
				if (ans[res1] == 0) {
					ans[res1] = 1;
					ok++;
					if (ok == n) {
						ok++;
						std::cout << "! ";
						for (auto [num, cnt] : ans) {
							if (cnt) {
								std::cout << num << " ";
							}
						}
						std::cout << std::endl;
						done = 1;
						return;
					}
					self(self, l, res1);
					if (done) {
						return;
					}
				}
				int res2 = vis[ask2] - 1;
				if (vis[ask2] == 0) {
					res2 = ask(ask2);
					vis[ask2] = res2 + 1;
				}
				if (ans[res2] == 0) {
					ans[res2] = 1;
					ok++;
					if (ok == n) {
						ok++;
						std::cout << "! ";
						for (auto [num, cnt] : ans) {
							if (cnt) {
								std::cout << num << " ";
							}
						}
						std::cout << std::endl;
						done = 1;
						return;
					}
					self(self, res2, r);
					if (done) {
						return;
					}
				}
				break;
			}
		}
	};

	work(work, min, max);
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