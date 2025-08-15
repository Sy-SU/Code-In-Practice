#include <bits/stdc++.h>

constexpr int N = 1e6 + 10;

struct SEG {
	int l, r;
}seg[N];

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> seg[i].l >> seg[i].r;
	}
	std::sort(seg + 1, seg + n + 1, [](SEG s1, SEG s2) {
		return s1.r < s2.r;
	});
	
	int cnt = 0, lst = -1;
	for (int i = 1; i <= n; i++) {
		if (seg[i].l >= lst) {
			cnt++;
			lst = seg[i].r;
		}
	}
	std::cout << cnt << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	solve();
	
	return 0;
} 
