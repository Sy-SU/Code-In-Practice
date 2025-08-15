#include <bits/stdc++.h>

using i64 = long long;

constexpr int Euler_Select_MAXN = 1e5 + 10; // 要筛的数的数量

bool Euler_Select_Num[Euler_Select_MAXN];  // 素数为0，合数为1
int Prime[Euler_Select_MAXN]; // Prime[i] 表示第 i 个素数 Prime[1] = 2, Prime[2] = 3

// 1e8 以下的素数有 5761455 个
// 1e7 以下的素数有 664579 个
// 1e6 以下的素数有 78498 个
// 1e5 以下的素数有 9592 个

void Euler_select(int n) // 求 1 ~ n 中的素数
{
	Euler_Select_Num[1] = Euler_Select_Num[0] = 1;
	int p_index = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!Euler_Select_Num[i])
		{
			Prime[++p_index] = i; // 将这个素数放入素数集中
		}
		for (int pj = 1; Prime[pj] * i <= n; pj++)
		{
			Euler_Select_Num[Prime[pj] * i] = 1;
			if (i % Prime[pj] == 0)
				break;
		}
	}
}

/*
	Euler_select(100000000); // 欧拉筛的范围
	int n, q;
	std::cin >> n >> q;
	while (q--)
	{
		int k;
		std::cin >> k;
		std::cout << Prime[k] << '\n'; // 查询第 k 个素数
		// i 为素数则 Num[i] 为 0
	}
*/

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	while (q--) {
		int op, x, y;
		std::cin >> op >> x >> y;

		if (op == 1) {
			a[x] = y;
		} else {
			std::map<i64, i64> count;
			for (int i = x; i <= y; i++) {
				i64 x = a[i], y = 1;
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
				count[y]++;
			}

			i64 ans = 0;
			for (const auto &[num, ct] : count) {
				ans += ct * (ct - 1) / 2;
			}
			std::cout << ans << '\n';
		}
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