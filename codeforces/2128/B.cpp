#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::vector<char> op;
	std::vector<int> q;
	int sz = 0;

	int l = 1, r = n;
	while (l <= r) {
		if (sz >= 4) {
			if (q[sz - 4] > q[sz - 3] && q[sz - 3] > q[sz - 2] && q[sz - 2] > q[sz - 1]) {
				// a[l], a[r]
				if (p[l] > q[sz - 1]) {
					op.push_back('L'), q.push_back(p[l]);
					sz++;
					l++;
				} else if (p[r] > q[sz - 1]) {
					op.push_back('R'), q.push_back(p[r]);
					sz++;
					r--;
				} else {
					op.pop_back(), q.pop_back();
					l--;

					op.push_back('R'), q.push_back(p[r]);
					r--;
				}
			} else if (q[sz - 4] < q[sz - 3] && q[sz - 3] < q[sz - 2] && q[sz - 2] < q[sz - 1]) {
				// a[l], a[r]
				if (p[l] < q[sz - 1]) {
					op.push_back('L'), q.push_back(p[l]);
					sz++;
					l++;
				} else if (p[r] < q[sz - 1]) {
					op.push_back('R'), q.push_back(p[r]);
					sz++;
					r--;
				} else {
					op.pop_back(), q.pop_back();
					l--;

					op.push_back('R'), q.push_back(p[r]);
					r--;
				}
			} else {
				op.push_back('L'), q.push_back(p[l]);
				l++;
				sz++;
			}
		} else {
			op.push_back('L'), q.push_back(p[l]);
			l++;
			sz++;
		}
	}

	for (auto c : op) {
		std::cout << c;
	}
	std::cout << '\n';
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