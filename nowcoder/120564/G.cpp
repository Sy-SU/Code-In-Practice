#include <bits/stdc++.h>

using i64 = long long;

i64 f(i64 x) {
	i64 res = 1;
	if (x == 0) {
		return 0;
	}
	while (x) {
		res *= (x % 10);
		x /= 10;
	}
	return res;
}

i64 g(i64 x) {
	int cnt = 0;
	while (x != f(x)) {
		// std::cerr << x << "->" << f(x) << '\n';
		x = f(x);
		cnt++;
	}
	return cnt;
}

int up[10] = {0, 0, 1, 1, 1, 0, 18, 18, 18, 18};

struct Node {
	int i2, i3, i4, i6, i7, i8, i9;
};

i64 pw(i64 a, i64 b) {
	i64 r = 1;
	for (int i = 1; i <= b; i++) {
		r *= a;
	}
	return r;
}

void solve() {
	i64 x;
	std::cin >> x;

	i64 best = 0;
	Node bestNode;
	for (int i2 = 0; i2 <= 4; i2++) {
		for (int i3 = 0; i3 <= 4; i3++) {
			for (int i4 = 0; i4 <= 4; i4++) {
				for (int i6 = 0; i6 <= 18; i6++) {
					for (int i7 = 0; i7 <= 18; i7++) {
						for (int i8 = 0; i8 <= 18; i8++) {
							for (int i9 = 0; i9 <= 18; i9++) {
								if (i2 + i3 + i4 + i6 + i7 + i8 + i9 > 20) {
									continue;
								}
								i64 tmp = pw(2, i2) * pw(3, i3) * pw(4, i4) * pw(6, i6) * pw(7, i7) * pw(8, i8) * pw(9, i9);
								i64 at = g(tmp);
								// if (best < at) {
								if (at == 10) {
									// std::cerr << at << '\n';
									best = at;
									bestNode = {i2, i3, i4, i6, i7, i8, i9};
									std::cout << tmp << '\n';
									std::cout << bestNode.i2 << " " << bestNode.i3 << " " << bestNode.i4 << " " << bestNode.i6 << " " << bestNode.i7 << " " << bestNode.i8 << " " << bestNode.i9 << '\n';
								}
							}
						}
					}
				}
			}
		}
	}
	std::cout << bestNode.i2 << " " << bestNode.i3 << " " << bestNode.i4 << " " << bestNode.i6 << " " << bestNode.i7 << " " << bestNode.i8 << " " << bestNode.i9 << '\n';
	std::cout << best << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}