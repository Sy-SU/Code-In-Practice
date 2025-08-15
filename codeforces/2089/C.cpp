#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE {
	int x, y;
	int dis;
	bool occ;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int MAXN = 3 * sqrt(3 * n + 100);
	std::vector<NODE> vec;
	for (int i = 1; i <= MAXN; i++) {
		for (int j = 1; i + j <= MAXN; j++) {
			if (i % 3 != 0 && j % 3 != 0) {
				int dis = 1e9;
				for (int d = 0; d < 4; d++) {
					if ((i + dx[d]) % 3 != 0 && (j + dy[d]) % 3 != 0) {
						continue;
					}
					dis = std::min(dis, i + dx[d] + j + dy[d]);
				}
				vec.push_back({i, j, dis, 0});
			}
		}
	}

	std::sort(vec.begin(), vec.end(), [](NODE n1, NODE n2) {
		return (n1.dis == n2.dis) ? ((n1.x == n2.x) ? (n1.y < n2.y) : (n1.x < n2.x)) : (n1.dis < n2.dis);
	});

	// std::cerr << vec.size() << "\n";
	// for (const auto &[x, y, d, o] : vec) {
	// 	std::cerr << x << " " << y << " " << d << " " << o << '\n';
	// }

	std::map<std::pair<int, int>, bool> vis;

	int ptr1 = 0, ptr0 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			while (vec[ptr1].occ == 1) {
				ptr1++;
			}
			std::cout << vec[ptr1].x << " " << vec[ptr1].y << '\n';
			vec[ptr1].occ = 1;
			vis[{vec[ptr1].x / 3 * 3, vec[ptr1].y / 3 * 3}] = 1;
		} else {
			while (vec[ptr0].occ == 1 || vis[{vec[ptr0].x / 3 * 3, vec[ptr0].y / 3 * 3}] == 1) {
				ptr0++;
			}
			std::cout << vec[ptr0].x << " " << vec[ptr0].y << '\n';
			vec[ptr0].occ = 1;
			vis[{vec[ptr0].x / 3 * 3, vec[ptr0].y / 3 * 3}] = 1;
		}
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