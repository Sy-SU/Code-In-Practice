#include <bits/stdc++.h>

using i64 = long long;

bool win[17][17];

struct TEAM {
	int id, seed, win, lose;
	std::vector<int> have;
}team[17];

int wincnt[17], losecnt[17];

bool cmp(TEAM t1, TEAM t2) {
	if (t1.win > t2.win) {
		return 1;
	} else if (t1.win < t2.win) {
		return 0;
	}

	int sum1 = 0, sum2 = 0;
	for (auto win1 : t1.have) {
		int tw = wincnt[win1], tl = losecnt[win1];
		sum1 += tw - tl;
	}

	for (auto win2 : t2.have) {
		int tw = wincnt[win2], tl = losecnt[win2];
		sum2 += tw - tl;
	}

	if (sum1 > sum2) {
		return 1;
	} else if (sum1 < sum2) {
		return 0;
	}

	return t1.id < t2.id;
}

int pri[15][6] = {
	{1, 6, 2, 5, 3, 4},
	{1, 6, 2, 4, 3, 5},
	{1, 5, 2, 6, 3, 4},
	{1, 5, 2, 4, 3, 6},
	{1, 4, 2, 6, 3, 5},
	{1, 4, 2, 5, 3, 6},
	{1, 6, 2, 3, 4, 5},
	{1, 5, 2, 3, 4, 6},
	{1, 3, 2, 6, 4, 5},
	{1, 3, 2, 5, 4, 6},
	{1, 4, 2, 3, 5, 6},
	{1, 3, 2, 4, 5, 6},
	{1, 2, 3, 6, 4, 5},
	{1, 2, 3, 5, 4, 6},
	{1, 2, 3, 4, 5, 6}
};

void solve() {
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 16 - i; j++) {
			bool w;
			std::cin >> w;
			win[i][i + j] = w;
			win[i + j][i] = 1 - w;
		}
	}

	std::map<std::pair<int, int>, bool> vis;
	for (int i = 1; i <= 16; i++) {
		team[i] = {i, i, 0, 0, {}};
	}

	// 第一轮

	auto battle = [&](int a, int b) -> void {
		assert(team[a].id == a);
		assert(team[b].id == b);
		if (win[team[a].id][team[b].id]) {
			// i win i + j
			team[a].win++, team[b].lose++;
			team[a].have.push_back(team[b].id);
			team[b].have.push_back(team[a].id);
		} else {
			team[b].win++, team[a].lose++;
			team[a].have.push_back(team[b].id);
			team[b].have.push_back(team[a].id);
		}

		vis[{a, b}] = vis[{b, a}] = 1;

		// std::cerr << "bt" << a << "(" << team[a].seed << ") " << b <<"(" << team[b].seed << ")" << '\n';
	};

	for (int i = 1; i <= 8; i++) {
		battle(i, i + 8);
	}

	for (int roud = 2; roud <= 3; roud++) {
		// std::cerr << "the " << roud << " round" << '\n';
		for (int i = 1; i <= 16; i++) {
			wincnt[i] = team[i].win;
			losecnt[i] = team[i].lose;
		}
		std::sort(team + 1, team + 17, cmp);
		for (int i = 1; i <= 16; i++) {
			team[i].seed = i;		
		}
		std::sort(team + 1, team + 17, [](TEAM t1, TEAM t2) {
			return t1.id < t2.id;
		});
		std::map<std::pair<int, int>, std::vector<int>> zhanji;
		for (int i = 1; i <= 16; i++) {
			int win = team[i].win, lose = team[i].lose;
			zhanji[{win, lose}].push_back(team[i].id);
		}

		for (auto [zj, vec] : zhanji) {
			int n = vec.size();
			std::vector<int> vs(17);
			// for (const auto & x : vec) {
			// 	std::cerr << zj.first << " " << zj.second << " " << x << '\n';
			// }
			std::sort(vec.begin(), vec.end(), [](int a, int b) {
				return team[a].seed < team[b].seed;
			});
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j > i; j--) {
					// std::cerr << "[DEBUG]" << vec[i] << " " << vec[j] <<'\n';
					if (vs[team[vec[j]].id] || vs[team[vec[i]].id]) {
						continue;
					}
					if (vis[{team[vec[i]].id, team[vec[j]].id}]) {
						continue;
					}

					battle(team[vec[i]].id, team[vec[j]].id);
					vs[team[vec[i]].id] = vs[team[vec[j]].id] = 1;
					break;
				}
			}
		}
	}

	// 第 4 轮
	// std::cerr << 4 << "========" << '\n';
	for (int i = 1; i <= 16; i++) {
		wincnt[i] = team[i].win;
		losecnt[i] = team[i].lose;
	}
	std::sort(team + 1, team + 17, cmp);
	for (int i = 1; i <= 16; i++) {
		team[i].seed = i;		
	}
	std::sort(team + 1, team + 17, [](TEAM t1, TEAM t2) {
		return t1.id < t2.id;
	});

	std::vector<int> drop(17);
	for (int i = 1; i <= 16; i++) {
		if (team[i].win >= 3 || team[i].lose >= 3) {
			drop[i] = 1;
		}
	}

	std::vector<int> group(7);
	int cnt = 0;
	for (int i = 1; i <= 16; i++) {
		if (drop[i] || cnt == 6) {
			continue;
		}
		if (team[i].win != 2 || team[i].lose != 1) {
			continue;
		}
		cnt++;
		drop[i] = 1;
		group[cnt] = i;
	}

	std::sort(group.begin(), group.end(), [](int a, int b) {
		return team[a].seed < team[b].seed;
	});
	for (int i = 0; i < 15; i++) {
		int tmp[6];
		for (int j = 0; j < 6; j++) {
			tmp[j] = pri[i][j];
		}
		// std::cerr << "check";
		// for (int i = 0; i < 6; i++) {
		// 	std::cerr << tmp[i];
		// }
		// std::cerr << '\n';
		if (vis[{group[tmp[0]], group[tmp[1]]}] || vis[{group[tmp[2]], group[tmp[3]]}] || vis[{group[tmp[4]], group[tmp[5]]}]) {
			continue;
		}

		battle(group[tmp[0]], group[tmp[1]]);
		battle(group[tmp[2]], group[tmp[3]]);
		battle(group[tmp[4]], group[tmp[5]]);
		break;
	}

	cnt = 0;
	for (int i = 1; i <= 16; i++) {
		if (drop[i] || cnt == 6) {
			continue;
		}
		if (team[i].win != 1 || team[i].lose != 2) {
			continue;
		}
		cnt++;
		drop[i] = 1;
		group[cnt] = i;
	}

	std::sort(group.begin(), group.end(), [](int a, int b) {
		return team[a].seed < team[b].seed;
	});
	for (int i = 0; i < 15; i++) {
		int tmp[6];
		for (int j = 0; j < 6; j++) {
			tmp[j] = pri[i][j];
		}
		if (vis[{group[tmp[0]], group[tmp[1]]}] || vis[{group[tmp[2]], group[tmp[3]]}] || vis[{group[tmp[4]], group[tmp[5]]}]) {
			continue;
		}

		battle(group[tmp[0]], group[tmp[1]]);
		battle(group[tmp[2]], group[tmp[3]]);
		battle(group[tmp[4]], group[tmp[5]]);
		break;
	}

	// 第 5 轮
	// std::cerr << 5 << "========" << '\n';
	for (int i = 1; i <= 16; i++) {
		wincnt[i] = team[i].win;
		losecnt[i] = team[i].lose;
	}

	cnt = 0;
	for (int i = 1; i <= 16; i++) {
		if (cnt == 6) {
			continue;
		}
		// std::cerr << i << " " << team[i].win << " " << team[i].lose << '\n';
		if (team[i].win >= 3 || team[i].lose >= 3) {
			continue;
		}
		cnt++;
		drop[i] = 1;
		group[cnt] = i;
	}

	std::sort(team + 1, team + 17, cmp);
	for (int i = 1; i <= 16; i++) {
		team[i].seed = i;		
	}
	std::sort(team + 1, team + 17, [](TEAM t1, TEAM t2) {
		return t1.id < t2.id;
	});

	cnt = 0;
	for (int i = 1; i <= 16; i++) {
		if (drop[i] || cnt == 6) {
			continue;
		}
		cnt++;
		drop[i] = 1;
		group[cnt] = i;
	}

	std::sort(group.begin(), group.end(), [](int a, int b) {
		return team[a].seed < team[b].seed;
	});
	for (int i = 0; i < 15; i++) {
		int tmp[6];
		for (int j = 0; j < 6; j++) {
			tmp[j] = pri[i][j];
		}
		if (vis[{group[tmp[0]], group[tmp[1]]}] || vis[{group[tmp[2]], group[tmp[3]]}] || vis[{group[tmp[4]], group[tmp[5]]}]) {
			continue;
		}

		battle(group[tmp[0]], group[tmp[1]]);
		battle(group[tmp[2]], group[tmp[3]]);
		battle(group[tmp[4]], group[tmp[5]]);
		break;
	}

	for (int i = 1; i <= 16; i++) {
		std::cout << team[i].win << " " << team[i].lose << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}