#include <bits/stdc++.h>

using i64 = long long;
#define int long long

constexpr long double PI = 3.141592653589793;

struct COMPLEX {
	double x, y;
	
	COMPLEX (long double _x = 0.0, long double _y = 0.0) {
		x = _x, y = _y;
	}

	COMPLEX operator + (const COMPLEX &n) const {
		return COMPLEX(x + n.x, y + n.y);
	}

	COMPLEX operator - (const COMPLEX &n) const {
		return COMPLEX(x - n.x, y - n.y);
	}

	COMPLEX operator * (const COMPLEX &n) const {
		return COMPLEX(x * n.x - y * n.y, x * n.y + y * n.x);
	}

	bool operator == (const COMPLEX &n) const {
		long double maxeps = 0;
		maxeps = std::max(std::abs(x - n.x), std::abs(y - n.y));
		return maxeps <= 1e-6;
	}

	void print() {
		std::cout << x << "+" << y << "i" << '\n';
	}
};

void change(std::vector<COMPLEX> &y, int len) {
	for (int i = 1, j = len / 2; i < len - 1; i++) {
		if (i < j) {
			std::swap(y[i], y[j]);
		}
		int k = len / 2;
		while (j >= k) {
			j -= k, k /= 2;
		}
		if (j < k) {
			j += k;
		}
	}
}

void FFT(std::vector<COMPLEX> &y, int len, int on) {
	change(y, len);
	for (int h = 2; h <= len; h <<= 1) {
		COMPLEX wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for (int j = 0; j < len; j += h) {
			COMPLEX w(1, 0);
			for (int k = j; k < j + h / 2; k++) {
				COMPLEX u = y[k];
				COMPLEX t = w * y[k + h / 2];
				y[k] = u + t, y[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}

	if (on == -1) {
		for (int i = 0; i < len; i++) {
			y[i].x /= len;
		}
	}
}


void solve() {
	std::string A, B;
	std::cin >> A >> B;

	int sza = A.size(), szb = B.size();
	int sz = 1;
	while (sz < sza * 2 || sz < szb * 2) {
		sz = sz * 2;
	}

	std::vector<COMPLEX> a(sz), b(sz);
	for (int i = 0; i < sza; i++) {
		a[i] = COMPLEX((A[sza - 1 - i] - '0') * 1.0, 0.0);
	}
	for (int i = sza; i < sz; i++) {
		a[i] = COMPLEX(0.0, 0.0);
	}

	for (int i = 0; i < szb; i++) {
		b[i] = COMPLEX((B[szb - 1 - i] - '0') * 1.0, 0.0);
	}
	for (int i = szb; i < sz; i++) {
		b[i] = COMPLEX(0.0, 0.0);
	}

	std::vector<COMPLEX> x = a, y = b;

	FFT(a, sz, 1), FFT(b, sz, 1);
	for (int i = 0; i < sz; i++) {
		a[i] = a[i] * b[i];
	}

	FFT(a, sz, -1);

	int para = 3 * sz + 100;

	std::vector<int> ans(para + 1);
	for (int i = 0; i < sz; i++) {
		ans[i] = (int)(a[i].x + 0.5);
	}

	// for (int i = sz; i >= 0; i--) {
	// 	std::cout << ans[i];
	// }
	// std::cout << '\n';

	for (int i = 0; i < para; i++) {
		if (ans[i] >= 2) {
			int num = (ans[i] - ans[i] % 2) / 2;
			ans[i + 2] -= num;
			ans[i] %= 2;
		} else if (ans[i] < 0) {
			int num = (std::abs(ans[i]) % 2 - ans[i]) / 2;
			ans[i + 2] += num;
			ans[i] = std::abs(ans[i]) % 2;
		}
	}

	sz = para;
	while (ans[sz] <= 0 && sz > 0) {
		sz--;
	}

	for (int i = sz; i >= 0; i--) {
		std::cout << ans[i];
	}
	std::cout << '\n';

	// COMPLEX ansx = 0, ansy = 0;
	// COMPLEX bx = COMPLEX(0.0, sqrtl(2)), bxx = COMPLEX(1.0, 0);
	// for (int i = 0; i < x.size(); i++) {
	// 	ansx = ansx + x[i] * bxx;
	// 	auto tx = bx;
	// 	bx = bxx * COMPLEX(-2.0, 0.0);
	// 	bxx = tx;
	// }
	// COMPLEX by = COMPLEX(0.0, sqrtl(2)), byy = COMPLEX(1.0, 0);
	// for (int i = 0; i < y.size(); i++) {
	// 	ansy = ansy + y[i] * byy;
	// 	auto ty = by;
	// 	by = byy * COMPLEX(-2.0, 0.0);
	// 	byy = ty;
	// }

	// COMPLEX ansa = 0, ba = COMPLEX(0.0, sqrtl(2)), baa = COMPLEX(1.0, 0);
	// for (int i = 0; i <= sz; i++) {
	// 	ansa = ansa + COMPLEX(ans[i], 0.0) * baa;
	// 	auto ta = ba;
	// 	ba = baa * COMPLEX(-2.0, 0.0);
	// 	baa = ta;
	// }

	// ansa.print();
	// ansx.print();
	// ansy.print();
	// COMPLEX ansm = ansx * ansy;
	// ansm.print();
	// if (ansa == ansm) {
	// 	// std::cout << "AC" << '\n';
	// } else {
	// 	std::cout << "WA" << '\n';
	// 	exit(-1);
	// }
}	

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}