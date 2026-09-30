#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, Q;
	std::cin >> n >> Q;

	std::vector<int> res(n + 1, -1);
	std::vector<std::pair<int, int>> task(60001);

	for (int i = 1; i <= n; i++) {
		int x, p, ti;
		std::cin >> x >> p >> ti;

		res[x] = ti;
		task[p] = {x, ti};
	}

	int tQ = Q;
	std::queue<int> q;
	for (int t = 1; t <= 60000; t++) {
		bool tag = 0;
		int r = 0;
		if (!q.empty()) {
			tQ--;
			res[q.front()]--;
			if (res[q.front()] == 0) {
				std::cout << q.front() << " " << t << '\n';
				q.pop();
				tQ = Q;
			} else if (tQ == 0) {
				tQ = Q;
				tag = 1;
				r = q.front();
				q.pop();
			}
		}
		if (task[t].first != 0) {
			q.push(task[t].first);
		}
		if (tag) {
			q.push(r);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}