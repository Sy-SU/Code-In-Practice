#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::string> vec;

	for (int i = 1; i <= 2 * n; i++) {
		std::string str;
		std::cin >> str;

		vec.push_back(str);
	}

	std::sort(vec.begin(), vec.end());
	std::vector<std::string> vec1, vec2;
	for (int i = 0; i < 2 * n; i++) {
		if (i % 2) {
			vec1.push_back(vec[i]);
		} else {
			vec2.push_back(vec[i]);
		}
	}	

	// int ansbf = 0;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		int k;
	// 		for (k = 0; k < std::min(vec1[i].size(), vec2[j].size()); k++) {
	// 			if (vec1[i][k] != vec2[j][k]) {
	// 				break;
	// 			}
	// 		}
	// 		ansbf += k;
	// 	}
	// }
	// std::cout << ansbf << '\n';

	i64 ans = 0;
	for (int _ = 0; _ < n; _++) {
		auto &str = vec1[_];
		// str 去对 vec2 中的字符串算前缀
		int l = 0, r = n - 1;
		int sz = str.size();
		for (int i = 0; i < sz; i++) {
			int lo = l, hi = r;
			bool find = 0;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (vec2[mid][i] >= str[i]) {
					hi = mid - 1;
					find = 1;
					l = mid;
				} else {
					lo = mid + 1;
				}
			}
			if (find == 0) {
				l = 1e9;
			}

			lo = l, hi = r;
			find = 0;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (vec2[mid][i] <= str[i]) {
					lo = mid + 1;
					find = 1;
					r = mid;
				} else {
					hi = mid - 1;
				}
			}
			if (find == 0) {
				l = 1e9;
			}

			if (l > r) {
				break;
			}
			ans += r - l + 1;
		}
	}
	std::cout << ans << '\n';
	// assert(ans == ansbf);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}