#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, k;
	std::cin >> n >> k;
	
	i64 ans = 0;
	int cnt1 = n, cnt2 = 0;
	for (int i = 1; i <= 1000; i++) 
	{
		ans += cnt2;
		cnt2 = cnt1, cnt1 = 0;
		cnt1 += cnt2 / k, cnt2 %= k;
	}
	std::cout << ans << '\n';
	return 0;
}
