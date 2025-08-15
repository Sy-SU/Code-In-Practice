#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

void solve() {
	int n;
	i64 y, M;
	std::cin >> n >> y >> M;

	std::vector<std::vector<i64>> a(n + 1);
	std::vector<int> l(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i];
		a[i].resize(l[i] + 1);
		for (int j = 1; j <= l[i]; j++) {
			std::cin >> a[i][j];
		}
	}

	auto checker = [&](i64 sta) -> int {
		i64 now = sta;
		for (int i = 1; i <= n; i++) {
			i64 to = 0, base = 1;
			for (int j = l[i]; j >= 1; j--) {
				if (a[i][j] >= now) {
					return -1;
				}
				to += a[i][j] * base;
				base *= now;

				if (base >= 1e9) {
					base = 1e9 + 1;
				}
				if (to >= 1e9) {
					to = 1e9 + 1;
				}
			}
			now = to;
			// std::cerr << now << "->" << to << '\n';
		}
		// std::cerr << "??? " << now << " " << y << '\n';
		if (now > y) {
			return 1;
		} else if (now < y) {
			return -1;
		} else {
			return 0;
		}
	};

	i64 lo = 2, hi = M;
	i64 ansl = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;
		// std::cerr << lo << " " << hi << " " << mid << " " << checker(mid) << '\n';
		if (checker(mid) != -1) {
			hi = mid - 1;
			ansl = mid;
		} else {
			lo = mid + 1;
		} 
	}

	lo = 2, hi = M;
	i64 ansr = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;
		if (checker(mid) != 1) {
			lo = mid + 1;
			ansr = mid;
		} else {
			hi = mid - 1;
		}
	}
    
    // std::cerr << ansl << " " << ansr << '\n';
	// assert(checker(ansl) ==  0 && checker(ansr) == 0);
	if (ansl > ansr) {
		std::cout << -1 << " " << -1 << '\n';
		return;
	}

	bool isINF = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].size() == 2) {
			isINF = 1;
		}
	}

	if (isINF) {
		std::cout << ansl << " " << M << '\n';
	} else {
		std::cout << ansl << " " << ansr << '\n';
	}

	// assert(checker());
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