#include <bits/stdc++.h>
using namespace std;

/* ===================== TYPE ALIASES ===================== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpll = vector<pll>;

/* ===================== CONSTANTS ===================== */
const ll INFLL = 4e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);

/* ===================== FAST IO ===================== */
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

/* ===================== DEBUG ===================== */
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

/* ===================== MATH ===================== */
ll add(ll a, ll b) { return (a + b) % MOD; }
ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

/* ===================== GCD / LCM ===================== */
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

/* ===================== DSU ===================== */
struct DSU
{
    vector<int> p, sz;
    DSU(int n = 0)
    {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
                swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
    }
};

/* ===================== SEGMENT TREE ===================== */
struct SegTree
{
    int n;
    vector<ll> t;

    SegTree(int _n)
    {
        n = _n;
        t.assign(4 * n, 0);
    }

    void build(int v, int tl, int tr, vector<ll> &a)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm, a);
            build(v * 2 + 1, tm + 1, tr, a);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, ll val)
    {
        if (tl == tr)
            t[v] = val;
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

/* ===================== GRAPH ===================== */
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

/* ===================== BFS ===================== */
vector<int> bfs(int src, vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

/* ===================== DIJKSTRA ===================== */
vector<ll> dijkstra(int src, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<ll> dist(n, INFLL);
    priority_queue<pll, vpll, greater<pll>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/* ===================== SOLVE ===================== */
void solve()
{
    string s;
    cin >> s;
    int one = 0, two = 0, three = 0, four = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '4')
        {
            count++;
        }
        else if (s[i] == '2')
        {
            two++;
        }
        else if (s[i] == '1')
        {
            if (one + three <= two)
            {
                count += (one + three);
                one = 0;
                three = 0;
                two = 0;
            }
            else
            {
                count += two;
                two = 0;
            }
            one++;
        }
        else
        {
            if (one + three <= two)
            {
                count += (one + three);
                one = 0;
                three = 0;
                two = 0;
            }
            else
            {
                count += two;
                two = 0;
            }
            three++;
        }
    }
    if (one + three <= two)
    {
        count += (one + three);
        one = 0;
        three = 0;
        two = 0;
    }
    else
    {
        count += two;
        two = 0;
    }
    cout << count << "\n";
}

/* ===================== MAIN ===================== */
int main()
{
    fastio;

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}