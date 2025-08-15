#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

constexpr int Euler_Select_MAXN = 1e6 + 10; // 要筛的数的数量

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
	int n;
	std::cin >> n;

	std::vector<i64> p(n + 1, -1);

	int pr = -1, mindis = 1e9;
	for (int i = 1; i <= n; i++) {
		if (Euler_Select_Num[i] == 0 && std::abs(i - n / 2) < mindis) {
			mindis = std::abs(i - n / 2);
			pr = i;
		}
	}

	std::vector<int> ok(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		p[i] = pr + (i % 2 ? 1 : -1) * (i / 2);
		if (p[i] <= 0 || p[i] >= n + 1) {
			p[i] = -1;
			break;
		}
		ok[p[i]] = 1;
	}

	std::vector<int> add;
	for (int i = 1; i <= n; i++) {
		if (ok[i] == 0) {
			add.push_back(i);
		}
	}

	int ptr = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] == -1) {
			p[i] = add[ptr++];
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
	}

	i64 sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		sum += p[i];
		cnt += Euler_Select_Num[(sum + i - 1) / i] == 0;
		// std::cout << (sum + i - 1) / i << " \n"[i == n];
	}
	assert(cnt >= (n / 3 - 1));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Euler_select(200000);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}