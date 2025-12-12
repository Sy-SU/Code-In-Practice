#include <bits/stdc++.h>

using i64 = long long;

bool Num[1000005];  // 素数为0，合数为1
int Prime[1000005]; // Prime[i] 表示第 i 个素数 Prime[1] = 2, Prime[2] = 3

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
    // std::cerr << p_index << '\n';
}

std::vector<std::vector<int>> mul(1000005);

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		cnt1 += a[i] == cnt1;
	}

	std::vector<int> b(2 * n);
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1];
	}
	for (int i = n; i < 2 * n; i++) {
		b[i] = a[i - n + 1];
	}

	std::set<int> needp;
	for (int i = 1; i <= n; i++) {
		// 对 a[i] 分解质因数
		for (int x = 2; x * x <= a[i]; x++) {
			bool isok = 0;
			while (a[i] % x == 0) {
				a[i] /= x;
				isok = 1;
			}

			if (isok) {
				needp.insert(x);
			}
		}
		if (a[i] != 1) {
			needp.insert(a[i]);
		} 
	}

	std::map<int, std::vector<int>> pos;

	for (int i = 1; i < 2 * n; i++) {
		pos[b[i]].push_back(i);
	}

	std::vector<int> fa(2 * n);
	for (int i = 1; i < 2 * n; i++) {
		fa[i] = i;
	}

	auto find = [&](auto &&self, int x) -> int {
		if (fa[x] == x) {
			return x;
		}
		return fa[x] = self(self, fa[x]);
	};

	auto merge = [&](int u, int v) -> void {
		fa[find(find, u)] = find(find, v);
	};

	for (auto p : needp) {
		// 含有同一个质因数的 数 对应的位置 连起来
		std::vector<int> pp;
		for (auto m : mul[p]) {
			for (auto posi : pos[m]) {
				pp.push_back(posi);
			}
		}

		std::sort(pp.begin(), pp.end());

		for (int i = 0; i + 1 < pp.size(); i++) {
			if (pp[i + 1] - pp[i] <= k) {
				merge(pp[i + 1], pp[i]);
				// std::cerr << pp[i + 1] << " " << pp[i] << '\n';
			}
		}
	}

	std::set<int> col;
	for (int i = 1; i < 2 * n; i++) {
		col.insert(fa[i]);
	}

	std::cout << col.size() + cnt1 * (n - 1) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	Euler_select(1000000);

	for (int i = 1; i <= 78498; i++) {
		for (int x = 1; x * Prime[i] <= 1000000; x++) {
			mul[Prime[i]].push_back(x * Prime[i]);
		}
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}