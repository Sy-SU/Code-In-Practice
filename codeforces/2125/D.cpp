#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p)
{
	i64 res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p)
{
	return qpow(x, p - 2, p);
}

struct SEG {
	int l, r;
	i64 p;
	bool operator > (const SEG &s) const {
		return (r == s.r ? l > s.l : r > s.r);
	}
};

struct NODE {
	int now;
	i64 mul, del;
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<SEG> vec(n + 1);
	std::vector<std::vector<std::pair<int, i64>>> edge(m + 1);

	for (int i = 1; i <= n; i++) {
		int l, r;
		i64 p, q;
		std::cin >> l >> r >> p >> q;

		vec[i] = {l, r, p * inv(q, mod) % mod};
		edge[l].push_back({r, vec[i].p});
	}

	i64 mulp = 1;
	for (int i = 1; i <= n; i++) {
		mulp = (mulp * (1 - vec[i].p + mod) % mod) % mod;
		assert(mulp >= 0 && mulp < mod);
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	q.push(0);

	std::vector<i64> sit(m + 1);
	sit[0] = 1;
	std::vector<int> inq(m + 1);
	while (!q.empty()) {
		auto now = q.top();
		// std::cerr << "vis" << now << " " << mul << " " << del << '\n';
		if (now == m) {
			// ans.push_back({mul, del});
			q.pop();
			continue;
		}

		q.pop();

		now++;
		for (auto [to, w] : edge[now]) {
			// std::cerr << now - 1 << "->" << to << " " << w << '\n';
			if (!inq[to]) {
				q.push(to);
				inq[to] = 1;
			}
			sit[to] = (sit[to] + sit[now - 1] * w % mod * inv(1 - w + mod, mod) % mod) % mod;
		}
	}

	// std::cerr << "==" << '\n';

	std::cout << sit[m] * mulp % mod << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}