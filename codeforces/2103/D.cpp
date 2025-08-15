#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int t = 1;
int testcase = 0;

void solve() {
	testcase++;
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// if (testcase == 48) {
	// 	for (int i = 0; i < n; i++) {
	// 		std::cout << a[i] << " \n"[i == n - 1];
	// 	}
	// 	return;
	// }

	// if (t >= 100) {
	// 	return;
	// }

	std::vector<int> pos(n, -1);
	int l = 1, r = n;
	for (int t = 1; t <= n; t++) {
		std::vector<int> todo;
		for (int i = 0; i < n; i++) {
			if (a[i] == t) {
				todo.push_back(i);
			}
		}
		if (todo.size() == 0) {
			break;
		}
		// todo 包含的是 这一轮需要赋值的下标
		// 我们需要把 todo 中的下标分成若干段
		// 可以断言这个段数一定大于等于 2
		// 我们需要特判一下段数为 奇数的情况
		std::vector<std::vector<int>> ok(n + 1);
		int now = 0;
		bool isok = 0;

		bool blockFr = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] == t) {
				ok[now].push_back(i);
				isok = 1;
			}
			if (a[i] == -1 || a[i] > t) {
				if (isok == 0) {
					blockFr = 1;
				}
				if (ok[now].size()) {
					now++;
				}
			}
		}
		int tsz = todo.size();
		std::vector<int> need; // 这一轮会用到的数
		while (tsz--) {
			if (t % 2) {
				need.push_back(r--);
			} else {
				need.push_back(l++);
			}

		}
		
		if (ok[now].size() == 0) {
			now--;
		}
		// std::cerr << "now = " << now << '\n';
		if (now % 2 == 0) {
			if (now == 0) {
				int lo = 0, hi = need.size() - 1;
				if (blockFr) {
					for (const auto &p : ok[0]) {
						pos[p] = need[hi--];
					}
				} else {
					for (const auto &p : ok[0]) {
						pos[p] = need[lo++];
					}
				}
			} else { 
				int lo = 0, hi = need.size() - 1;
				// std::cerr << "l h" << lo << " " << hi << '\n';
				int szok = ok.size() - 1;
				// std::cerr << szok << '\n';
				for (int i = 0; i < szok; i++) {
					// std::cerr << "vis" << i << '\n';
					if (i % 2 == 0 || i == 1) {
						for (const auto &p : ok[i]) {
							pos[p] = need[lo++];
							// std::cerr << "pos1 " << p << "<-" << pos[p] << '\n';
						}
					} else {
						for (const auto &p : ok[i]) {
							pos[p] = need[hi--];
							// std::cerr << "pos2 " << p << "<-" << pos[p] << '\n';
						}
					}
				}
			}

		} else {
			int lo = 0, hi = need.size() - 1;
			int szok = ok.size() - 1;
			for (int i = 0; i < szok; i++) {
				if (i % 2 == 0) {
					for (const auto &p : ok[i]) {
						pos[p] = need[lo++];
						// std::cerr << "pos3 " << p << "<-" << pos[p] << '\n';
					}
				} else {
					for (const auto &p : ok[i]) {
						pos[p] = need[hi--];
						// std::cerr << "pos4 " << p << "<-" << pos[p] << '\n';
					}
				}
			}
		}
		// int xx = 0;
		// for (const auto &v : ok) {
		// 	std::cerr << xx++ << " :";
		// 	for (const auto &num : v) {
		// 		std::cerr << num << ' ';
		// 	}
		// 	std::cerr << '\n';
		// }
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			pos[i] = l;
			assert(l == r);
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << pos[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
