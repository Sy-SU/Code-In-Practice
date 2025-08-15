#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int MAXN = 1e6 + 10; // 要筛的数的数量

bool Num[MAXN];  // 素数为0，合数为1
int Prime[MAXN]; // Prime[i] 表示第 i 个素数 Prime[1] = 2, Prime[2] = 3

// 1e8 以下的素数有 5761455 个
// 1e7 以下的素数有 664579 个
// 1e6 以下的素数有 78498 个
// 1e5 以下的素数有 9592 个

void Euler_select(int n) // n为数组长度
{
    Num[1] = Num[0] = 1;
    int p_index = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!Num[i])
        {
            Prime[++p_index] = i; // 将这个素数放入素数集中
        }
        for (int pj = 1; Prime[pj] * i <= n; pj++)
        {
            Num[Prime[pj] * i] = 1;
            if (i % Prime[pj] == 0)
                break;
        }
    }
}
void solve() {
	int n;
	std::cin >> n;

	Euler_select(1000000);
	std::vector<int> vec;
	for (int i = 1; i <= 70000; i++) {
		if (Prime[i] > n) {
			vec.push_back(Prime[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << vec[i - 1] * i << " \n"[i == n];
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}