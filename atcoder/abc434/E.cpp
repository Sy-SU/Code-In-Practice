#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<i64, i64>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 x, r;
		std::cin >> x >> r;

		vec[i] = {x - r, x + r};
	}

	std::sort(vec.begin() + 1, vec.end(), [](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
	});

	std::map<i64, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[vec[i].first]++;
	}

	std::map<i64, i64> oth;

	for (int i = n; i >= 1; i--) {
		auto [now, nxt] = vec[i];
		if (cnt[nxt] == 0) {
			cnt[now]--, cnt[nxt]++;
			oth[nxt] = now;
		} else {
			if 
			oth[now] = nxt;
		}
	}

	int ans = 0;
	for (auto [ind, mul] : cnt) {
		ans += mul > 0;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}