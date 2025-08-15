#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int f1[N], p1[N], f2[N], p2[N];

int p[N];

void solve() {
	int n, m, r;
	std::cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		std::cin >> f1[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> p1[i];
	}
 	for (int i = 1; i <= n; i++) {
 		std::cin >> f2[i];
 	}
 	for (int i = 1; i <= n; i++) {
 		std::cin >> p2[i];
 	}
 	for (int i = 1; i <= n; i++) {
 		std::cin >> p[i];
 	}

 	int cnt = 0;
 	for (int i = 1; i <= n; i++) {
 		// f1[p[i]] p1[p[i]]
 		int nowf = f1[p[i]], nowp = p1[p[i]];
 		int idx = -1;
 		for (int j = 1; j <= n; j++) {
 			if (f2[j] == nowf && p2[j] > nowp) {
 				if (p2[j] > p2[idx]) {
 					idx = j;
 				}
 			}
 		}
 		if (idx != -1) {
 			cnt++;
 			f2[idx] = p2[idx] = -1;
 		}
 	}
 	std::cout << n - cnt << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}