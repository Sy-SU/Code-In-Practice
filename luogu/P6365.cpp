#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i];
		b[i] ^= a[i];
	}

	std::map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		if (a[i] != b[i]) {
			cnt[b[i]]++;
		}
	}

	int max = 0, maxnum = 2e9;
	for (const auto& [num, ct] : cnt) {
		if (ct > max) { 
			maxnum = num;
			max = ct;
		} else if (ct == max) {
			if (num < maxnum) {
				maxnum = num;
				max = ct;
			}
		}
	}
	std::cout << maxnum << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}