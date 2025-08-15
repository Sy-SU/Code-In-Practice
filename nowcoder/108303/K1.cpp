#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

    std::vector<int> a(n + 1), d(n + 1);
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(30)), fd(n + 1, std::vector<int>(30));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i][0] = a[i];
        fd[i][0] = a[i] - a[i-1];
    }

    for (int j = 1; j <= log(n) / log(2); j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = 0;
            fd[i][j] = 0;
        }
    }

    for (int j = 1; j <= log(n) / log(2); j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = std::__gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        	fd[i][j] = std::__gcd(fd[i][j - 1], fd[i + (1 << (j - 1))][j - 1]);
        }
    }

    std::vector<int> preg(n + 2), sufg(n + 2);
    for (int i = 1; i <= n; i++) {
        preg[i] = std::__gcd(preg[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        sufg[i] = std::__gcd(sufg[i + 1], a[i]);
    }

    bool isok = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[1]) {
            isok = 0;
            break;
        }
    }
    if (isok) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> pv, sv;
    pv.push_back({0, 0}), sv.push_back({n + 1, 0});
    for (int i = 1; i <= n; i++) {
        if (preg[i] != preg[i + 1]) {
            pv.push_back({i, preg[i]});
        }
    }

    for (int i = n; i >= 1; i--) {
        if (sufg[i] != sufg[i - 1]) {
            sv.push_back({i, sufg[i]});
            //std::cerr << "s" << i << " " << sufg[i] << '\n';
        }
    }

    auto query = [&](int l, int r) -> int {
        l++;
        int x = log(r - l + 1) / log(2);
        if(l >= r) return 0ll;
        return std::__gcd(fd[l][x], fd[r - (1 << x) + 1][x]);
    };

    int szp = (int)pv.size(), szs = (int)sv.size();

    int ans = 0;
    for (int bp = 0; bp < szp; bp++) {
        for (int bs = 0; bs < szs; bs++) {
            // 1 .. bp | bp + 1 .. bs - 1 | bs .. n
            int gcdp = pv[bp].second, gcds = sv[bs].second;
            int lef = pv[bp].first, rig = sv[bs].first;
            int gg = std::__gcd(gcdp, gcds);
            int gcdm = 0;
            if (lef + 1 < rig - 1) {
                gcdm = query(lef + 1, rig - 1);
            }

            //std::cerr << "1 .. " << lef << " " << rig << ".. n" << '\n';
            //std::cerr << std::__gcd(gcdm, gg) << '\n';

            //std::cerr << gcdp << " " << gcds << '\n';
            //std::cerr << '\n';

            ans = std::max(ans, std::__gcd(gcdm, gg));
        }
    }
    std::cout << ans << '\n';
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