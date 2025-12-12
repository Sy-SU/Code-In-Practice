#include <bits/stdc++.h>

using i64 = long long;

bool cmp(std::vector<int> v1, std::vector<int> v2) {
	int l1 = v1.size(), l2 = v2.size();
	for (int i = 0; i < std::min(l1, l2); i++) {
		if (v1[i] < v2[i]) {
			return 1;
		} else if (v1[i] > v2[i]) {
			return 0;
		}
	}
	return l1 < l2;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n);
	int maxk = 0;
	for (int i = 0; i < n; i++) {
		int k;
		std::cin >> k;

		maxk = std::max(maxk, k);

		for (int j = 1; j <= k; j++) {
			int x;
			std::cin >> x;
			a[i].push_back(x);	
		}
	}

	int r = -1;

	auto v = a;
	while (1) {
		if (v.empty()) {
			break;
		}
		std::sort(v.begin(), v.end(), cmp);
		// std::cerr << "===" << '\n';
		// for (auto vec : v) {
		// 	for (auto num : vec) {
		// 		std::cerr << num << " ";
		// 	}
		// 	std::cerr << '\n';
		// }
		// std::cerr << "===" << '\n';
		auto min = v[0];
		int len = min.size();

		for (auto num : min) {
			std::cout << num << " ";
		}

		std::vector<std::vector<int>> tmp;
		for (auto vec : v) {
			if (vec.size() > len) {
				std::vector<int> t;
				for (int i = len; i < vec.size(); i++) {
					t.push_back(vec[i]);
				}
				tmp.push_back(t);
			}
		}
		v = tmp;
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