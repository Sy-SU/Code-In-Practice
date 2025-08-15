#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

constexpr int Euler_Select_MAXN = 1e7 + 10; // 要筛的数的数量

bool Euler_Select_Num[Euler_Select_MAXN];  // 素数为0，合数为1
int Prime[Euler_Select_MAXN]; // Prime[i] 表示第 i 个素数 Prime[1] = 2, Prime[2] = 3

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

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	i64 sumP = 0;
	for (int i = 1; i <= n; i++) {
		sumP += Prime[i];
	}

	i64 sumA = 0;
	for (int i = 1; i <= n; i++) {
		sumA += a[i];
	}

	for (int cnt = 0; cnt <= n; cnt++) {
		if (sumA >= sumP) {
			std::cout << cnt << '\n';
			return;
		}
		sumA -= a[cnt + 1];
		sumP -= Prime[n - cnt];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Euler_select(10000000);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}