#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::pair<int, int> node0, node1, node2;

	std::cin >> node0.first >> node0.second;
	std::cin >> node1.first >> node1.second;
	std::cin >> node2.first >> node2.second;

	if (node1 > node2) {
		std::swap(node1, node2);
	}

	auto calc = [&](std::pair<int, int> s, std::pair<int, int> t) -> int {
		// 从 s -> t
		// costh * 5 + costm
		int costh = std::min(std::abs((s.first * 60 + s.second) - (t.first * 60 + t.second)), 12 * 60 - std::abs((s.first * 60 + s.second) - (t.first * 60 + t.second)));
		int costm = std::min(std::abs(s.second - t.second), 60 - std::abs(s.second - t.second));
		
		return 5 * costh + costm * 60;
	};

	// std::cerr << calc(node0, node1) << " " << calc(node0, node2) << '\n';


	int cost = 1e9;
	std::pair<int, int> ans = {12, 60};
	for (int h = 0; h < 12; h++) {
		for (int m = 0; m < 60; m++) {
			std::pair<int, int> now = {h, m};
			if (now > node2 || now < node1) {
				continue;
			}

			int nowcost = calc(node0, now);
			if (nowcost < cost) {
				cost = nowcost, ans = now;
			} else if (nowcost == cost) {
				if (ans > now) {
					ans = now;
				}
			}
		}
	}
	std::cout << ans.first << " " << ans.second << '\n';
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