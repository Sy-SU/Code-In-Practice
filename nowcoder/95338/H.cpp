#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct QUERY {
	int l, r, c;
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	std::vector<QUERY> vec;
	for (int i = 1; i <= m; i++) {
		int l, r, c;
		std::cin >> l >> r >> c;
		vec.push_back({l, r, c});
	}

	if (vec[0].l % 2 != vec[0].r % 2) {
		for (int i = n; i >= 1; i--) {
			std::cout <<  p[i] << " \n"[i == 1];
		}
	} else {
		int now1 = 1, now2 = 2;
		for (int i = 1; i <= n; i += 2) {
			p[i] = now2;
			now2 += 2;
		}
		for (int i = 2; i <= n; i += 2) {
			p[i] = now1;
			now1 += 2;
		}
		if (p[n] > n) {
			p[n] = n;
		}
        std::map<int, int> cnt;
		for (int i = n; i >= 1; i--) {
            if (cnt[p[i]] == 1) {
                exit(-1);
            }
            if (p[i] > n) {
                while (1) {
                    
                }
            }
			std::cout << p[i] << " \n"[i == 1];
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