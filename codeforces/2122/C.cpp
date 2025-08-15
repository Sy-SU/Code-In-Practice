#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	int id;
	std::pair<i64, i64> pos;
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<NODE> p(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 x, y;
		std::cin >> x >> y;

		p[i] = {i, {x, y}};
	}

	std::sort(p.begin() + 1, p.end(), [](NODE n1, NODE n2) {
		return n1.pos < n2.pos;
	});

	std::vector<NODE> A, B;
	for (int i = 1; i <= n / 2; i++) {
		A.push_back(p[i]), B.push_back(p[n + 1 - i]);
	}

	std::sort(A.begin(), A.end(), [](NODE n1, NODE n2) {
		return n1.pos.second == n2.pos.second ? n1.pos.first < n2.pos.first : n1.pos.second < n2.pos.second;
	});

	std::sort(B.begin(), B.end(), [](NODE n1, NODE n2) {
		return n1.pos.second == n2.pos.second ? n1.pos.first < n2.pos.first : n1.pos.second > n2.pos.second;
	});
 
	// i64 sum = 0;
	for (int i = 0; i < n / 2; i++) {
		std::cout << A[i].id << " " << B[i].id << '\n';
		// sum += std::abs(A[i].pos.first - B[i].pos.first) + std::abs(A[i].pos.second - B[i].pos.second);
	}
	// std::cerr << "sum" << sum << '\n';
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