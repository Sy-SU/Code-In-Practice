#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
/* ---------- 线段树（区间加 / 区间和） ---------- */
struct SegTree {
    struct Node { int64 sum, tag; };
    int n;
    vector<Node> tr;
    SegTree(int _n = 0) { init(_n); }
    void init(int _n) {
        n = _n;
        tr.assign(4 * n + 4, {0, 0});
    }
    inline void apply(int p, int l, int r, int64 v) {
        tr[p].sum += v * (r - l + 1);
        tr[p].tag += v;
    }
    inline void push(int p, int l, int r) {
        if (!tr[p].tag) return;
        int m = (l + r) >> 1;
        apply(p << 1, l, m, tr[p].tag);
        apply(p << 1 | 1, m + 1, r, tr[p].tag);
        tr[p].tag = 0;
    }
    inline void pull(int p) {
        tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
    }
    void rangeAdd(int L, int R, int64 v) { rangeAdd(1, 1, n, L, R, v); }
    void rangeAdd(int p, int l, int r, int L, int R, int64 v) {
        if (L <= l && r <= R) { apply(p, l, r, v); return; }
        push(p, l, r);
        int m = (l + r) >> 1;
        if (L <= m) rangeAdd(p << 1, l, m, L, R, v);
        if (R >  m) rangeAdd(p << 1 | 1, m + 1, r, L, R, v);
        pull(p);
    }
    int64 rangeSum(int L, int R) { return rangeSum(1, 1, n, L, R); }
    int64 rangeSum(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) return tr[p].sum;
        push(p, l, r);
        int m = (l + r) >> 1; int64 res = 0;
        if (L <= m) res += rangeSum(p << 1, l, m, L, R);
        if (R >  m) res += rangeSum(p << 1 | 1, m + 1, r, L, R);
        return res;
    }
};
 
/* ---------- 全局常量 & 数据结构 ---------- */
const int MAXN = 100000 + 5;
const int B = 320;                  // heavy 阈值 (≈ sqrt(MAXN))
 
int n, q, sRoot;
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN], depthArr[MAXN], eulerTime;
int flat2id[MAXN];
int64 initVal[MAXN];
 
vector<int> depthList[MAXN];        // depth → list of tin
vector<int> heavyDepths;            // 存 heavy depth id
int64 heavyAdd[MAXN];               // 该层累计加值
 
/* ---------- DFS 预处理 Euler 序、深度 ---------- */
void dfs(int u, int p) {
    tin[u] = ++eulerTime;
    flat2id[tin[u]] = u;
    depthList[ depthArr[u] ].push_back(tin[u]);
    for (int v : g[u]) if (v != p) {
        depthArr[v] = depthArr[u] + 1;
        dfs(v, u);
    }
    tout[u] = eulerTime;
}
 
/* ---------- 主程序 ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;  if (!(cin >> T)) return 0;
    while (T--) {
 
        /* ---------- 读输入 ---------- */
        cin >> n >> q >> sRoot;
 
        for (int i = 1; i <= n; ++i) g[i].clear(), depthList[i].clear();
        for (int i = 1; i <= n; ++i) cin >> initVal[i];
        for (int i = 1;i < n; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }
 
        /* ---------- 预处理 ---------- */
        eulerTime = 0;
        depthArr[sRoot] = 1;
        dfs(sRoot, 0);
        int maxDepth = 0;
        for (int i = 1; i <= n; ++i) maxDepth = max(maxDepth, depthArr[i]);
 
        /* 标 heavy depth */
        heavyDepths.clear();
        for (int d = 1; d <= maxDepth; ++d) {
            if ((int)depthList[d].size() >= B) heavyDepths.push_back(d);
            heavyAdd[d] = 0;
        }
 
        /* 建全局线段树，写入初始值 */
        SegTree seg(n);
        for (int pos = 1; pos <= n; ++pos) {
            seg.rangeAdd(pos, pos, initVal[ flat2id[pos] ]);
        }
 
        /* ---------- 处理 q 次操作 ---------- */
        while (q--) {
            int opt;  cin >> opt;
            if (opt == 1) {
                int t; long long k, x;  cin >> t >> k >> x;
                int targetDepth = depthArr[t] + (int)k;
                if (targetDepth > maxDepth) continue;
 
                const auto &vec = depthList[targetDepth];
                if (vec.empty()) continue;
 
                int L = tin[t], R = tout[t];
                int li = lower_bound(vec.begin(), vec.end(), L) - vec.begin();
                int ri = upper_bound(vec.begin(), vec.end(), R) - vec.begin() - 1;
                if (li > ri) continue;
 
                if ((int)vec.size() >= B) {          // heavy depth
                    heavyAdd[targetDepth] += x;
                } else {                             // light depth —— 逐点写全局线段树
                    for (int idx = li; idx <= ri; ++idx) {
                        seg.rangeAdd(vec[idx], vec[idx], x);
                    }
                }
 
            } else if (opt == 2) {
                int t;  cin >> t;
                int L = tin[t], R = tout[t];
                int64 ans = seg.rangeSum(L, R);      // 已写进树的部分
 
                // 加上 heavy depth 累积贡献
                for (int d : heavyDepths) if (heavyAdd[d]) {
                    const auto &vec = depthList[d];
                    int cnt = upper_bound(vec.begin(), vec.end(), R)
                            - lower_bound(vec.begin(), vec.end(), L);
                    if (cnt) ans += 1LL * cnt * heavyAdd[d];
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
