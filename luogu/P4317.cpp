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

using Z = ModInt<10000007>;

void solve() {
	i64 n;
	std::cin >> n;

	std::vector<int> a;
	i64 tmp = n;
	while (tmp) {
		a.push_back(tmp % 2);
		tmp /= 2;
	}

	int len = a.size();

	std::vector<std::vector<Z>> f(60, std::vector<Z>(100, 0));

	auto dfs = [&](auto &&self, int pos, bool limit, i64 sum) -> Z {
		if (pos == -1) {
			// std::cerr << pos << " " << sum << '\n';
			if (sum == 0) {
				return 1;
			}
			return sum;
		}

		if (!limit && f[pos][sum] != 0) {
			return f[pos][sum];
		}

		Z res = 1;
		int up = limit ? a[pos] : 1;
		for (int i = 0; i <= up; i++) {
			res *= self(self, pos - 1, limit && (a[pos] == i), sum + i);
		}

		if (!limit) {
			f[pos][sum] = res;
		}

		return res;
	};

	std::cout << dfs(dfs, len - 1, 1, 0) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}