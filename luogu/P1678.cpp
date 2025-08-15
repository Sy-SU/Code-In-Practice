#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int s[N], t[N];

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i]; // 录取分数 
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> t[i]; // 估分成绩 
	}
	
	std::sort(s + 1, s + n + 1); 
	i64 sum = 0;
	
	for (int i = 1; i <= m ; i++) {
		// 第 i 名学生的估分成绩是 t[i]
		
		// 大于等于 t[i] 的最小 s[j]
		int l = 1, r = n;
		int ans = 1e9;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (s[mid] >= t[i]) {
				r = mid - 1;
				ans = s[mid] - t[i];
			} else {
				l = mid + 1;
			}
		} 
		
		// 小于等于 t[i] 的最大 s[j] 
		l = 1, r = n;
		int _ans = 1e9;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (s[mid] <= t[i]) {
				l = mid + 1;
				_ans = t[i] - s[mid];
			} else {
				r = mid - 1;
			}
		}
		
		sum += std::min(ans, _ans);
	} 
	std::cout << sum << '\n';

	

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}