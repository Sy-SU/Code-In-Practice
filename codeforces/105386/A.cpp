#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m; 
	i64 k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<i64>> p(n + 1, std::vector<i64>(m + 1, 0));
	std::vector<int> s(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		for (int j = 1; j <= m; j++) {
			std::cin >> p[i][j];
		}
	}

	std::vector<std::pair<i64, int>> node(n + 1, {0ll, 0});
	for (int i = 1; i <= n; i++) {
		i64 sum = 0;
		for (int j = 1; j <= m; j++) {
			if (p[i][j] == -1) {
				node[i].second++;
			} else {
				node[i].first += p[i][j];
			}
		}
	}

	std::vector<std::pair<int, int>> ind(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		ind[i] = {s[i], i};
	}
	std::sort(ind.begin() + 1, ind.end());
	// ind[i].second 表示顺序为 i 的行
	std::vector<std::pair<int, i64>> limit;
	// limit[i].first 表示 limit 对应的 s, second 表示对应的 sum
	limit.push_back({-1, -1});
	for (int i = 1; i <= n; i++) {
		int h = ind[i].second;
		i64 nowsum = node[h].first; // 当前行和
		// s[h] > or = limit.back().first
		// std::cerr << "s = " << s[h] << '\n';
		// std::cerr << "limit" << limit.back().first << " " << limit.back().second << '\n';
		i64 need = (s[h] > limit.back().first ? limit.back().second : limit[(int)limit.size() - 2].second) - nowsum;
		need = std::max(0ll, need);
		// std::cerr << nowsum << " " << need << '\n';
		for (int j = 1; j <= m; j++) {
			if (p[h][j] == -1) {
				p[h][j] = std::min(k, need);
				nowsum += p[h][j];
				need -= std::min(k, need);
			}
		}
		// for (int j = 1; j <= m; j++) {
		// 	std::cerr << p[h][j] << " \n"[j == m];
		// }
		// std::cerr << "need = " << need << '\n';
		if (need > 0) {
			std::cout << "No" << '\n';
			return;
		}

		if (ind[i].first > limit.back().first) {
			// 如果当前的 s 大于 limit 最后的
			// 把这个塞进去
			limit.push_back({ind[i].first, nowsum + 1});
		} else {
			// 否则更新最后的 second
			limit[(int)limit.size() - 1].second = std::max(limit[(int)limit.size() - 1].second, nowsum + 1);
		}
	}

 	std::cout << "Yes" << '\n';
 	std::vector<std::pair<int, i64>> vec;
 	for (int i = 1; i <= n; i++) {
 		i64 sum = 0;
 		for (int j = 1; j <= m; j++) {
 			sum += p[i][j];
 			std::cout << p[i][j] << " \n"[j == m];
 			assert(p[i][j] >= 0 && p[i][j] <= k);
 		}
 		vec.push_back({s[i], sum});
 	}
 	std::sort(vec.begin(), vec.end());
 	int lstind = -1, lstval = -1;
 	for (int i = 0; i < (int)vec.size(); i++) {
 		if (vec[i].first > lstind) {
 			assert(vec[i].second > lstval);
 			lstind = vec[i].first;
 			lstval = vec[i].second;
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