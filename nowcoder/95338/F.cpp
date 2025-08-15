#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::pair<i64, i64> off[N];

int sta[N], ed[N];

int lst[N];

void solve() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> off[i].first >> off[i].second;
		off[i].second += off[i].first;
	}

	std::sort(off + 1, off + n + 1, [](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return p1.first < p2.first;
		// return (p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second);
	});

	int blklen = sqrt(n), blkcnt = 0;
	for (int i = 1; i <= n; i += blklen) {
		blkcnt++;
		sta[blkcnt] = i, ed[blkcnt] = std::min(n, i + blklen - 1);
	}

	for (int blkind = 1; blkind <= blkcnt; blkind++) {
		int s = sta[blkind], e = ed[blkind];
		for (int i = s; i <= e; i++) {
			int now = i;
			for (int j = i + 1; j <= e; j++) {
				if (off[j].first > off[now].second) {
					now = j;
				}
			}
			lst[i] = now;
		}
	}

	i64 ans = 0;
	for (int sta = 1; sta <= n; sta++) {
		
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