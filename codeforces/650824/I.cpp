#include <bits/stdc++.h>

using i64 = long long;

template<int MOD>
struct ModInt {
    static_assert(MOD > 0, "MOD must be positive");

    int v;

    ModInt() : v(0) {}
    template<class T>
    ModInt(T x) {
        long long t = (long long)x % MOD;
        if (t < 0) t += MOD;
        v = (int)t;
    }

    static constexpr int mod() { return MOD; }
    int val() const { return v; }

    ModInt& operator+=(const ModInt& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& o) {
        v = (int)((__int128)v * o.v % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& o) {
        return *this *= o.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
    ModInt operator-() const { return ModInt(v ? MOD - v : 0); }

    friend bool operator==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.v != b.v; }

    ModInt pow(long long e) const {
        ModInt res = 1, base = *this;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        return pow(MOD - 2);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        return os << a.v;
    }
    friend std::istream& operator>>(std::istream& is, ModInt& a) {
        long long x; is >> x;
        a = ModInt(x);
        return is;
    }
};

using Z = ModInt<1000000007>;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	std::vector<Z> p(m + 1), b(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	std::vector<int> l(n + 1), r(n + 1);
	std::vector<Z> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> mb(m + 2);
	std::vector<Z> ma(m + 2, 1);

	for (int q = 1; q <= n; q++) {
		if (s[q - 1] == '0') {
			mb[l[q]]--, mb[r[q] + 1]++;
		} else if (s[q - 1] == '1') {
			mb[l[q]]++, mb[r[q] + 1]--;
			ma[l[q]] *= a[q], ma[r[q] + 1] /= a[q];
		}
	}

	i64 nowb = 0;
	Z nowa = 1;
	for (int i = 1; i <= m; i++) {
		nowb += mb[i], nowa *= ma[i];

		i64 normb = nowb;
		if (normb < 0) {
			normb = normb + 1000000007 - 1;
		}
		// std::cerr << normb << " " << nowa << '\n';
		p[i] = p[i] * b[i].pow(normb) * nowa;
	}

	Z ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += p[i];
		// std::cerr << p[i] << " \n"[i == m];
	}
	ans /= m;

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}