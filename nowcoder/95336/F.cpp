#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE {
	int pos;
	i64 val;
} node1[N * 4], node2[N * 4];

void solve() {
	int n, p, k;
	std::cin >> n >> p >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] %= p;
	}

	std::sort(a.begin() + 1, a.end(), std::greater<int>());

	std::vector<i64> sum1(n + 1, -1), sum2(n + 1, -1); // 进位， 不进位
	std::vector<int> ptr1(n + 1, -1), ptr2(n + 1, -1);

	for (int i = 1; i < n; i++) {
		int lo = i + 1, hi = n;
		int pos = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (a[i] + a[mid] < p) {
				hi = mid - 1;
				pos = mid;
			} else {
				lo = mid + 1;
			}
		}
		if (pos != -1) {
			sum2[i] = a[i] + a[pos];
			ptr2[i] = pos;
		}
		if (a[i] + a[i + 1] >= p) {
			sum1[i] = a[i] + a[i + 1];
			ptr1[i] = i + 1;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << sum1[i] << " \n"[i == n];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << sum2[i] << " \n"[i == n];
	// }

	for (int i = 1; i <= 4 * n; i++) {
		node1[i] = node2[i] = {-1, 0};
	}

	int b = 0;
	for (int i = 0; i <= 30; i++) {
		if ((1 << i) >= n) {
			b = i;
			break;
		}
	}

	for (int i = (1 << b); i < (1 << b) + n; i++) {
		if (sum1[i - (1 << b) + 1] == -1) {
			node1[i] = {i - (1 << b) + 1,-1};
		} else {
			node1[i] = {i - (1 << b) + 1, sum1[i - (1 << b) + 1] - p};
		}
		node2[i] = {i - (1 << b) + 1, sum2[i - (1 << b) + 1]};
	}
	for(int i = (1 << b) + n; i < (1 << (b + 1)); i++) {
		node1[i] = node2[i] = {-1, -1};
	}

	auto max = [&](NODE n1, NODE n2) -> NODE {
		return (n1.val > n2.val ? n1 : n2);
	};

	for (int i = (1 << b) - 1; i >= 1; i--) {
		node1[i] = max(node1[i << 1], node1[i << 1 | 1]);
		node2[i] = max(node2[i << 1], node2[i << 1 | 1]);
	}

	// for (int i = 1; i <= 16; i++) {
	// 	std::cerr << node1[i].pos << " \n"[i == 16];
	// }
	// for (int i = 1; i <= 16; i++) {
	// 	std::cerr << node1[i].val << " \n"[i == 16];
	// }
	// std::cerr << '\n';

	while (k--) {
		NODE n1 = node1[1], n2 = node2[1];
		// std::cerr << n1.val << " " << n2.val << '\n';
		if (n1.val > n2.val) {
			std::cout << n1.val << " ";

			int now = (1 << b) + n1.pos - 1;
			ptr1[now - (1 << b) + 1]++;
			if (ptr1[now - (1 << b) + 1] > n || a[now] + a[ptr1[now - (1 << b) + 1]] < p) {
				node1[now] = {n1.pos, -1};
			} else {
				node1[now] = {n1.pos, a[now] + a[ptr1[now - (1 << b) + 1]] - p};
			}

			now /= 2;
			while (now) {
				// std::cerr << "now" << now << '\n';
				node1[now] = max(node1[now << 1], node1[now << 1 | 1]);
				now /= 2;
			}
		} else {
			std::cout << n2.val << " ";

			int now = (1 << b) + n2.pos - 1;
			ptr2[now - (1 << b) + 1]++;
			if (ptr2[now - (1 << b) + 1] > n) {
				node2[now] = {n2.pos, -1};
			} else {
				node2[now] = {n2.pos, a[now] + a[ptr2[now - (1 << b) + 1]]};
			}

			now /= 2;
			while (now) {
				// std::cerr << "now" << now << '\n';
				node2[now] = max(node2[now << 1], node2[now << 1 | 1]);
				now /= 2;
			}
		}

		// for (int i = 1; i <= 16; i++) {
		// 	std::cerr << node1[i].pos << " \n"[i == 16];
		// }
		// for (int i = 1; i <= 16; i++) {
		// 	std::cerr << node1[i].val << " \n"[i == 16];
		// }
		// std::cerr << '\n';
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