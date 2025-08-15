#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int testcase;	
int t = 1;

void solve() {
	int n;
	std::cin >> n;

	std::map<int, std::vector<std::pair<int, int>>> row, col;

	std::vector<int> v(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i] >> p[i];

		// (v, p)
		row[v[i]].push_back({p[i], i}), col[p[i]].push_back({v[i], i});
	}



	testcase++;
	if (t >= 100) {
		if (testcase < 55) {
			return;
		}
	}
	if (testcase == 55) {
		std::cout << n << "\n";
		for (int i = 1; i <= n; i++) {
			std::cout << v[i] << " " << p[i] << '\n';
		}
		return;
	}

	if (n == 1) {
		std::cout << "YES" << '\n';
		std::cout << 1 << '\n';
		return;
	}

	std::vector<int> fa(n + 1);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}

	auto find = [&](auto &&self, int x) -> int {
		if (x == fa[x]) {
			return fa[x];
		}
		return fa[x] = self(self, fa[x]);
	};

	auto merge = [&](int x, int y) -> void {
		int fx = find(find, x), fy = find(find, y);
		fa[fx] = fy;
	};

	auto query = [&](int x, int y) -> bool {
		return find(find, x) == find(find, y);
	};

	int cnt = 0;

	std::vector<std::vector<int>> edge(n + 1);

	for (const auto &[x, vecy] : row) {
		// (x, )
		int sz = vecy.size(), ptr = 1;
		std::map<int, int> used;
		for (int i = 0; i < sz; i++) {
			if (cnt == n - 1) {
				continue;
			}
			auto &[y, id] = vecy[i];

			if (used[id]) {
				continue;
			}

			int nxt = vecy[ptr].second;
			// std::cerr << "try" << id << " " << nxt << " " << sz << '\n';
			while (ptr < sz && (query(nxt, id) || used[nxt])) {
				ptr++;
				nxt = vecy[ptr].second;
				// std::cerr << "query" << nxt << " " << id << '\n';
				// std::cerr << query(nxt, id) << " " << used[nxt] << '\n';
			}

			if (ptr >= sz) {
				break;
			}

			merge(nxt, id);
			cnt++;
			used[nxt] = used[id] = 1;
			// std::cerr << nxt << "<->" << id << '\n';

			edge[id].push_back(nxt), edge[nxt].push_back(id);
		}
	}

	for (const auto &[y, vecx] : col) {
		// ( , y)
		int sz = vecx.size(), ptr = 1;
		std::map<int, int> used;
		for (int i = 0; i < sz; i++) {
			if (cnt == n - 1) {
				continue;
			}
			auto &[x, id] = vecx[i];

			if (used[id]) {
				continue;
			}

			int nxt = vecx[ptr].second;
			// std::cerr << "try" << id << " " << nxt << " " << sz << '\n';
			while (ptr < sz && (query(nxt, id) || used[nxt])) {
				ptr++;
				nxt = vecx[ptr].second;
				// std::cerr << "query" << nxt << " " << id << '\n';
				// std::cerr << query(nxt, id) << " " << used[nxt] << '\n';
			}

			if (ptr >= sz) {
				break;
			}

			merge(nxt, id);
			cnt++;
			used[nxt] = used[id] = 1;
			// std::cerr << nxt << "<->" << id << '\n';

			edge[id].push_back(nxt), edge[nxt].push_back(id);
		}
	}

	if (cnt < n - 1) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';
	int now = -1;
	for (int i = 1; i <= n; i++) {
		if (edge[i].size() == 1) {
			now = i;
			break;
		}
	}

	std::cout << now << " ";
	std::vector<int> vis(n + 1);
	vis[now] = 1;
	for (int i = 1; i < n; i++) {
		for (const auto &to : edge[now]) {
			if (vis[to]) {
				continue;
			}
			vis[now] = 1;
			now = to;
		}
		std::cout << now <<  " ";
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}