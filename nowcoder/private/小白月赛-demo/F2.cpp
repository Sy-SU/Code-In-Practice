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
 
	std::vector<i64> f(n + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = fr(a[i]);
	}
 
	int blklen = sqrt(50 * n), blknum = (n + blklen - 1) / blklen;
 
	auto getSta = [&](int ind) -> int {
		return (ind - 1) * blklen + 1;
	};
 
	auto getEd = [&](int ind) -> int {
		return std::min(n, ind * blklen);
	};
 
	auto blkInd = [&](int ind) -> int {
		return (ind - 1) / blklen + 1;
	};
 
	std::vector<std::vector<i64>> block(blknum + 1, std::vector<i64>(101));
	for (int bi = 1; bi <= blknum; bi++) {
		int sta = getSta(bi), ed = getEd(bi);
		for (int i = sta; i <= ed; i++) {
			block[bi][f[i]]++;
		}
	}
 
	while (q--) {
		int op, x, y;
		std::cin >> op >> x >> y;
 
		if (op == 1) {
			int z;
			std::cin >> z;
			if (blkInd(x) == blkInd(y)) {
				for (int i = x; i <= y; i++) {
					block[blkInd(i)][f[i]]--, block[blkInd(i)][fr(z)]++;
					a[i] = z, f[i] = fr(z);
				}
			} else {
				int bx = blkInd(x), by = blkInd(y);
				for (int i = x; i <= getEd(bx); i++) {
					block[blkInd(i)][f[i]]--, block[blkInd(i)][fr(z)]++;
					a[i] = z, f[i] = fr(z);
				}
				for (int i = getSta(by); i <= y; i++) {
					block[blkInd(i)][f[i]]--, block[blkInd(i)][fr(z)]++;
					a[i] = z, f[i] = fr(z);
				}
				for (int bi = bx + 1; bi <= by - 1; bi++) {
					for (int num = 1; num <= 100; num++) {
						
					}
				}
			}
		} else {
			std::vector<i64> cnt(101);
			if (blkInd(x) == blkInd(y)) {
				for (int i = x; i <= y; i++) {
					cnt[f[i]]++;
				}
			} else {
				int bx = blkInd(x), by = blkInd(y);
				for (int i = x; i <= getEd(bx); i++) {
					cnt[f[i]]++;
				} 
				for (int i = getSta(by); i <= y; i++) {
					cnt[f[i]]++;
				}
				for (int bi = bx + 1; bi <= by - 1; bi++) {
					for (int num = 1; num <= 100; num++) {
						cnt[num] += block[bi][num];
					}
				}
			}
 
			i64 ans = 0;
			for (const auto &ct : cnt) {
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
