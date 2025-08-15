#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	i64 del, res;
};

void solve() {
	int n, p;
	i64 k, m;
	std::cin >> n >> m >> k >> p;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<NODE> node(n + 1);
	for (int i = 1; i <= n; i++) {
		node[i] = {a[i] / k, a[i] % k};
	}

	std::sort(node.begin() + 1, node.end(), [](NODE n1, NODE n2) {
		return n1.del > n2.del;
	});

	int ptr = p - 1;
	i64 sum = 0;
	for (int i = ptr + 1; i <= n; i++) {
		sum += node[i].del;
	}

	std::priority_queue<i64> pq;
	for (int i = ptr + 1; i <= n; i++) {
		pq.push(node[i].res);
	}

	i64 ans = 0, get = 0;
	while (ptr >= 1) {
		// 1 .. ptr | ptr + 1 .. n
		// ptr, x = p - ptr

		while (ptr >= 1 && node[ptr].del < sum / (p - ptr)) {
			sum += node[ptr].del, pq.push(node[ptr].res);
			ptr--;
		}

		// 1 .. ptr | ptr + 1 .. n
		// 左半部分最小值 大于等于 右半部分的和 / x 
		// x 是每次需要从右半部分拿的数量

		i64 op = sum / (p - ptr); // 操作次数

		for (int i = 1; i <= ptr; i++) {
			node[i].del -= sum / op;
		}

		ans += sum / op;
		sum %= (p - ptr);
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