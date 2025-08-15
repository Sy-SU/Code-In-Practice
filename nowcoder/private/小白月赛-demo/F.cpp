#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr int Euler_Select_MAXN = 1e5 + 10; // 要筛的数的数量
 
bool Euler_Select_Num[Euler_Select_MAXN];  // 素数为0，合数为1
int Prime[Euler_Select_MAXN]; // Prime[i] 表示第 i 个素数 Prime[1] = 2, Prime[2] = 3
 
void Euler_select(int n) {
	Euler_Select_Num[1] = Euler_Select_Num[0] = 1;
	int p_index = 0;
	for (int i = 2; i <= n; i++) {
		if (!Euler_Select_Num[i]) {
			Prime[++p_index] = i; // 将这个素数放入素数集中
		}
		for (int pj = 1; Prime[pj] * i <= n; pj++) {
			Euler_Select_Num[Prime[pj] * i] = 1;
			if (i % Prime[pj] == 0)
				break;
		}
	}
}
 
void solve() {
	int n, q;
	std::cin >> n >> q;
 
	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
 
	auto fr = [&](i64 x) -> i64 {
		int y = 1;
		for (int pi = 1; Prime[pi] * Prime[pi] <= x && pi < 9592; pi++) {
			int cnt = 0;
			while (x % Prime[pi] == 0) {
				cnt++;
				x /= Prime[pi];
				}
			y *= (cnt % 2 ? Prime[pi] : 1);
		}
		if (x > 1) {
			y *= x;
		}
		return y;
	};
 
	std::vector<int> f(100001);
	for (int i = 1; i <= 100000; i++) {
		f[i] = fr(i);
	}
 
	while (q--) {
		int x, y;
		std::cin >> x >> y;

		
	}
}
 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
 
	Euler_select(100000);
 
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}
