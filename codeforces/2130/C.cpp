#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> seg(n + 1);
	std::map<std::pair<int, int>, int> ind;
	for (int i = 1; i <= n; i++) {
		std::cin >> seg[i].first >> seg[i].second;
		ind[seg[i]] = i;
	}

	std::sort(seg.begin() + 1, seg.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
		return (p1.second - p1.first) < (p2.second - p2.first);
	});

	std::vector<int> fa(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		fa[i] = i;
	}

	auto find = [&](auto &&self, int x) -> int {
		if (fa[x] == x) {
			return x;
		}
		return fa[x] = self(self, fa[x]);
	};

	auto merge = [&](int x, int y) -> void {
		int fx = find(find, x), fy = find(find, y);
		fa[fx] = fy;
	};

	std::vector<std::pair<int, int>> chs;

	for (int i = 1; i <= n; i++) {
		auto [l, r] = seg[i];
		if (find(find, l) == find(find, r)) {
			continue;
		}
		chs.push_back({l, r});
		merge(l, r);
	}

	std::cout << chs.size() << '\n';
	for (auto [l, r] : chs) {
		std::cout << ind[{l, r}] << " ";
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