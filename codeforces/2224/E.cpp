#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    i128 d = exgcd(b, a % b, x, y);
    i128 t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}


void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 2; i <= n; i++) {
		int f;
		std::cin >> f;

		adj[f].push_back(i);
	}

	std::vector<i64> l(n + 1);
	for (int i = 2; i <= n; i++) {
		std::cin >> l[i];
	}

	std::vector<std::pair<i128, i128>> sol(n + 1);
	std::vector<int> leaf(n + 1);

	auto dfs = [&](auto &&self, int u, int f) -> void {
		auto [modu, resu] = sol[u];
		int soncnt = adj[u].size();
		int idx = 0;
		if (soncnt == 0) {
			leaf[u] = 1;
		}
		for (auto v : adj[u]) {
			i128 tmodv = soncnt, tresv = idx++;
			i128 modv = -1, resv = -1;
			if (modu != -1 && resu != -1) {
				// modv, rev <- modu, resu tmodv, tresv
				i128 g = std::gcd(modu, tmodv);
				if (resu % g == tresv % g) {
					i128 a = modu / g, b = tmodv / g;
					i128 k = (resu - tresv) / g;
					i128 x, y;
					i128 d = exgcd(a, b, x, y);
					i128 x0 = resu - modu * x * k;
					i128 lcm = modu / g * tmodv;
					x0 %= lcm;
					if (x0 < 0) {
						x0 += lcm;
					}
					modv = lcm, resv = x0;
				}
				sol[v] = {modv, resv};
			}
		}
	};

	dfs(dfs, 1, 0);

	for (int i = 1; i <= n; i++) {
		if (leaf[i] == 0) {
			continue;
		}
		auto [mod, res] = sol[i];
	}

	while (q--) {
		i64 m;
		std::cin >> m;


	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}