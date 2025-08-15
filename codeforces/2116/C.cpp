#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

constexpr int Euler_Select_MAXN = 1e4 + 10; // 要筛的数的数量

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

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int g = 0;
	for (int i = 1; i <= n; i++) {
		g = std::__gcd(g, a[i]);
	}

	for (int i = 1; i <= n; i++) {
		a[i] /= g;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] == 1;
	}

	if (cnt) {
		std::cout << n - cnt << '\n';
		return;
	}

	std::vector<std::vector<int>> have(n + 1);
	for (int i = 1; i <= n; i++) {
		int x = 1;
		for (int pi = 1; Prime[pi] <= a[i]; pi++) {
			if (a[i] % Prime[pi] == 0) {
				x *= Prime[pi];
				have[i].push_back(Prime[pi]);
			}
		}
		a[i] = x;
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	int ans = 100000;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		std::vector<int> tmpans(5000 + 1);
		tmpans[0] = 0;
		std::vector<int> ok;
		for (int s = 0; s < (1 << (int)have[i].size()); s++) {
			int _s = s;
			int idx = 0, mul = 1;
			while (_s) {
				if (_s % 2) {
					mul *= have[i][idx];
				}
				idx++;
				_s /= 2;
			}
			ok.push_back(mul);
		}
		for (const auto &m : ok) {
			tmpans[m] = 1e9;
		}	
		ok.push_back(0);
		std::set<int> st;
		for (int j = i; j <= n; j++) {
			if (i == j) {
				continue;
			}
			int b = std::__gcd(a[i], a[j]);
			st.insert(b);
		}
		for (const auto &nw : st) {
			for (const auto &m : ok) {
				int to = std::__gcd(m, nw);
				tmpans[to] = std::min(tmpans[to], tmpans[m] + 1);
			}
		}
		ans = std::min(ans, tmpans[1] + n - cnt - 1);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Euler_select(10000);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}