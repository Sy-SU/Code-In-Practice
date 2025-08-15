#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	std::map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		cnt[a[i]]++;
	}	
	int chs = -1;
	for (const auto &[num, ct] : cnt) {
		if (ct >= 2) {
			chs = num;
		}
	}
	if (chs == -1) {
		std::cout << -1 << '\n';
		return;
	}
	int need = 2;
	std::vector<int> vec;
	for (int i = 1; i <= n; i++) {
		if (a[i] == chs) {
			if (need >= 1) {
				need--;
			} else {
				vec.push_back(a[i]);
			}
		} else {
			vec.push_back(a[i]);
		}
	}
	std::sort(vec.begin(), vec.end());
	int x = -1, y = -1;
	for (int i = 1; i < (int)vec.size(); i++) {
		if (vec[i] - vec[i - 1] < 2 * chs) {
			x = vec[i], y = vec[i - 1];
			break;	
		}
	}
	if (x == -1) {
		std::cout << -1 << '\n';
		return;
	}
	std::cout << chs << " " << chs << " " << x << " " << y << '\n';

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