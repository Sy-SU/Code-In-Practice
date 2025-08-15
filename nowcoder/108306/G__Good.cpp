#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	int op = pow(3, n);
	std::set<std::vector<int>> st;
	for (int s = 0; s < op; s++) {
		int _s = s;
		std::string str;
		for (int i = 1; i <= n; i++) {
			if (_s % 3 == 0) {
				str += "L";
			} else if (_s % 3 == 1) {
				str += "R";
			} else {
				str += "Q";
			}
			_s /= 3;
		}

		int l = 1, r = n;
		std::vector<int> arr;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'L') {
				l++;
			} else if (str[i] == 'R') {
				r--;
			} else {
				int min = 1e9;
				for (int j = l; j <= r; j++) {
					min = std::min(min, p[j]);
				}
				arr.push_back(min);
			}
		}
		st.insert(arr);
	}

	std::cout << "cnt = " << st.size() << '\n';
	std::vector<int> cnt(n + 1);
	for (auto ar : st) {
		cnt[ar.size()]++;
		for (auto num : ar) {
			std::cout << num << " ";
		}
		std::cout << '\n';
	}
	for (int i = 0; i <= n; i++) {
		std::cout << "cnt = " << i << " : " << cnt[i] << '\n';
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