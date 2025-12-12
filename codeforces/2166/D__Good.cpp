#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> freq(n + 1, 0);
        for (int x : a) ++freq[x];
        vector<int> fs;
        for (int i = 1; i <= n; ++i) {
            if (freq[i] > 0) fs.push_back(freq[i]);
        }
        sort(fs.rbegin(), fs.rend());
        int mm = fs.size();
        if (mm == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector<ll> psum(mm + 1, 0);
        vector<ll> pprod(mm + 1, 1LL);
        for (int i = 1; i <= mm; ++i) {
            psum[i] = psum[i - 1] + fs[i - 1];
            pprod[i] = pprod[i - 1] * (fs[i - 1] % MOD) % MOD;
        }
        vector<ll> dp(n + 1, 0LL);
        dp[0] = 1LL;
        ll answer = pprod[mm];
        for (int ki = mm; ki >= 1; --ki) {
            int idx = ki - 1;
            ll fk = fs[idx];
            ll pres = psum[ki - 1];
            ll th = fk - pres;
            int startt = (th <= 0 ? 0 : (th > n ? n + 1 : (int)th));
            ll sump = 0;
            for (int s = startt; s <= n; ++s) {
                sump = (sump + dp[s]) % MOD;
            }
            ll prepr = pprod[ki - 1];
            ll con = prepr * sump % MOD;
            answer = (answer + con) % MOD;
            // update
            vector<ll> ndp(n + 1, 0LL);
            for (int s = 0; s <= n; ++s) {
                ll val = dp[s];
                ndp[s] = (ndp[s] + val) % MOD;
                int ns = s + (int)fk;
                if (ns <= n) {
                    ndp[ns] = (ndp[ns] + val * (fk % MOD) % MOD) % MOD;
                }
            }
            dp = move(ndp);
        }
        cout << answer << '\n';
    }
    return 0;
}