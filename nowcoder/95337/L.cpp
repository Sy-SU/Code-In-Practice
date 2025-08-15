#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

struct NODE {
	int x, y, z;
};

void solve() {
	int n;
	std::cin >> n;

	int lst = 0;
	std::vector<NODE> vec;
	for (int i = 1; i + 5 <= n; i += 6) {
		vec.push_back({i, i + 1, i + 3});
		vec.push_back({i + 2, i + 4, i + 5});
		lst = i + 5;
	}

	std::vector<int> res;
	for (int i = lst + 1; i <= n; i++) {
		res.push_back(i);
	}

	if (res.size() == 3) {
		if (vec.size() >= 2) {
			vec.pop_back(), vec.pop_back();
			res.push_back(res[0] - 1);
			res.push_back(res[0] - 2);
			res.push_back(res[0] - 3);
			res.push_back(res[0] - 4);
			res.push_back(res[0] - 5);
			res.push_back(res[0] - 6);
			std::sort(res.begin(), res.end());
			vec.push_back({res[0], res[1], res[3]});
			vec.push_back({res[2], res[4], res[8]});
			vec.push_back({res[5], res[6], res[7]});
		}
		
	} else if (res.size() == 4) {
		vec.push_back({res[0], res[1], res[3]});
	} else if (res.size() == 5) {
		vec.push_back({res[0], res[1], res[3]});
	}
	// std::map<int, int> cc;
	std::cout << vec.size() << '\n';
	for (const auto &[x, y, z] : vec) {
		std::cout << x << " " << y << " " << z << '\n';
		// assert(cc[x] == 0 && cc[y] == 0 && cc[z] == 0);
		// cc[x] = cc[y] = cc[z] = 1;
		// int cnt = (std::__gcd(x, y) == 1) + (std::__gcd(y, z) == 1) + (std::__gcd(z, x) == 1);
		// assert(cnt == 2);
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