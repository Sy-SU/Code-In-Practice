#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::vector<int>> depth_dfn;

/* ---------------- 1D 段树：区间加 / 区间求和 ---------------- */
struct Seg1D {
    int n{};
    std::vector<i64> sum, tag;          // sum 保存区间和，tag 为懒标记（整段加）

    Seg1D() = default;
    explicit Seg1D(int _n) { init(_n); }

    void init(int _n) {
        n = _n - 1;
        sum.assign(4 * n + 4, 0);
        tag.assign(4 * n + 4, 0);
    }

    /* 建树：a 必须是 1-indexed，长度 = n */
    void build(const std::vector<i64>& a, int p, int l, int r) {
        if (l == r) {
            sum[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, p << 1, l, mid);
        build(a, p << 1 | 1, mid + 1, r);
        pull(p);
    }
    void build(const std::vector<i64>& a) { 
        init(a.size());
        build(a, 1, 1, n); 
    }

    /* 区间加 */
    void range_add(int L, int R, i64 v) { range_add(1, 1, n, L, R, v); }

    /* 区间和 */
    i64 range_sum(int L, int R) { return range_sum(1, 1, n, L, R); }

    /* ------- 底层实现 ------- */
private:
    void apply(int p, int len, i64 v) {
        sum[p] += v * len;
        tag[p] += v;
    }
    void push(int p, int l, int r) {
        if (tag[p] == 0) return;
        int mid = (l + r) >> 1;
        apply(p << 1, mid - l + 1, tag[p]);
        apply(p << 1 | 1, r - mid,   tag[p]);
        tag[p] = 0;
    }
    void pull(int p) { sum[p] = sum[p << 1] + sum[p << 1 | 1]; }

    void range_add(int p, int l, int r, int L, int R, i64 v) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            apply(p, r - l + 1, v);
            return;
        }
        push(p, l, r);
        int mid = (l + r) >> 1;
        range_add(p << 1, l, mid, L, R, v);
        range_add(p << 1 | 1, mid + 1, r, L, R, v);
        pull(p);
    }
    i64 range_sum(int p, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return sum[p];
        push(p, l, r);
        int mid = (l + r) >> 1;
        return range_sum(p << 1, l, mid, L, R) +
               range_sum(p << 1 | 1, mid + 1, r, L, R);
    }
};

/* -------- 2-D 线段树：外层 depth，内层 dfn（坐标表动态归并） -------- */
class Seg2D {
public:
    /* 仅给出行数 nDepth；列坐标表在 build 时动态决定 */
    explicit Seg2D(int nDepth = 0) { init(nDepth); }

    /* 必须同时传入：
       A[dep]  —— 该深度每个点（按 dfn 升序）的权值（0 占位，1-indexed）
       func[dep] —— 同层 dfn 表，对应 A 的列坐标（0 占位，1-indexed） */
    void build(const std::vector<std::vector<i64>>& A,
               const std::vector<std::vector<int>>& func)
    {
        build(1, 1, n, A, func);
    }

    /* 单点（depth = x） × dfn 区间 [yL,yR] 加 v */
    void add(int xDepth, int dfnL, int dfnR, i64 v) {
        update(1, 1, n, xDepth, dfnL, dfnR, v);
    }

    /* 深度区间 [xL,xR] × dfn 区间 [yL,yR] 的和 */
    i64 query(int xL, int xR, int dfnL, int dfnR) {
        return query(1, 1, n, xL, xR, dfnL, dfnR);
    }

private:
    int n{};                                         // 最大深度
    std::vector<Seg1D> seg;                          // 每个外层结点一棵 1-D 段树
    std::vector<std::vector<int>> coord;             // coord[p]：该结点的坐标表

    void init(int nDepth) {
        n = nDepth;
        seg.assign(4 * n + 4, Seg1D());              // 段树稍后 init
        coord.assign(4 * n + 4, {});                 // 坐标表稍后填
    }

/* ------------------- 建树 ------------------- */
    void build(int p, int l, int r,
               const std::vector<std::vector<i64>>& A,
               const std::vector<std::vector<int>>& func)
    {
        if (l == r) {                                // 叶：单一 depth
            coord[p] = func[l];                      // 0 占位，1-indexed
            int m = (int)coord[p].size() - 1;
            seg[p].init(m);
            seg[p].build(A[l]);                      // A[l] 与 coord[p] 同长度
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1,     l,     mid, A, func);
        build(p << 1 | 1, mid + 1, r,   A, func);

        /* ---- 归并 coord ---- */
        const auto &Lc = coord[p << 1];
        const auto &Rc = coord[p << 1 | 1];
        coord[p].resize(Lc.size() + Rc.size() - 1);
        std::merge(Lc.begin() + 1, Lc.end(),
                   Rc.begin() + 1, Rc.end(),
                   coord[p].begin() + 1);
        coord[p][0] = 0;

        /* ---- 新建本结点的 1-D 段树，导入左右儿子值 ---- */
        int m = (int)coord[p].size() - 1;
        seg[p].init(m);                              // 初始全 0
        import_child(p, p << 1,     Lc);
        import_child(p, p << 1 | 1, Rc);
    }

    /* 把 childIdx 的叶子值搬到父节点 dstIdx */
    void import_child(int dstIdx, int childIdx,
                      const std::vector<int>& childCoord)
    {
        Seg1D &src = seg[childIdx];
        Seg1D &dst = seg[dstIdx];
        const auto &pc  = coord[dstIdx];
        for (int i = 1; i < (int)childCoord.size(); ++i) {
            i64 v = src.range_sum(i, i);
            if (!v) continue;
            int pos = std::lower_bound(pc.begin() + 1, pc.end(), childCoord[i])
                       - pc.begin();
            dst.range_add(pos, pos, v);             // point-update
        }
    }

/* ------------------- 基础工具 ------------------- */
    /* 在结点 p 的坐标表中，找到 dfn 区间对应的压缩下标区间 */
    std::pair<int,int> get_cmp(int p, int dfnL, int dfnR) const {
        const auto &v = coord[p];
        int L = std::lower_bound(v.begin() + 1, v.end(), dfnL) - v.begin();
        int R = std::upper_bound(v.begin() + 1, v.end(), dfnR) - v.begin() - 1;
        return {L, R};                              // L>R 表示本结点无点落入
    }

/* ------------------- 更新 ------------------- */
    void update(int p, int l, int r, int xDepth,
                int dfnL, int dfnR, i64 v)
    {
        auto [L, R] = get_cmp(p, dfnL, dfnR);
        if (L <= R) seg[p].range_add(L, R, v);

        if (l == r) return;
        int mid = (l + r) >> 1;
        if (xDepth <= mid)
            update(p << 1, l, mid, xDepth, dfnL, dfnR, v);
        else
            update(p << 1 | 1, mid + 1, r, xDepth, dfnL, dfnR, v);
    }

/* ------------------- 查询 ------------------- */
    i64 query(int p, int l, int r, int Ld, int Rd,
              int dfnL, int dfnR)
    {
        if (Rd < l || r < Ld) return 0;
        if (Ld <= l && r <= Rd) {
            auto [L, R] = get_cmp(p, dfnL, dfnR);
            return (L <= R) ? seg[p].range_sum(L, R) : 0;
        }
        int mid = (l + r) >> 1;
        return query(p << 1, l, mid, Ld, Rd, dfnL, dfnR) +
               query(p << 1 | 1, mid + 1, r, Ld, Rd, dfnL, dfnR);
    }
};

void solve() {
    int n, q, s;
    std::cin >> n >> q >> s;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;

        edge[u].push_back(v), edge[v].push_back(u);
    }

    int maxd = 0, idx = 0;
    std::vector<int> depth(n + 1), fat(n + 1), dfn(n + 1), dfnR(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        depth[u] = depth[fa] + 1, fat[u] = fa, dfn[u] = ++idx;
        maxd = std::max(maxd, depth[u]);
        for (const auto &v : edge[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
        dfnR[u] = idx;
    };

    // depth[s] = 1;
    dfs(dfs, s, 0);

    // [depth, dfn] -> val

    // 比对 dfn 的时候，需要拿 l, r 和 func[dep][i] 比

    std::vector<std::vector<i64>> arr(maxd + 1, {0});
    std::vector<std::vector<int>> func(maxd + 1, {0});
    depth_dfn.clear();
    depth_dfn.resize(maxd + 1);
    // func[dep][ind] -> dfn
    auto dfs1 = [&](auto &&self, int u, int fa) -> void {
        arr[depth[u]].push_back(a[u]); // depth[u] 的 第 ind 个 -> a[u]
        func[depth[u]].push_back(dfn[u]);
        depth_dfn[depth[u]].push_back(dfn[u]);
        for (const auto &v : edge[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, s, 0);

    for (int d = 1; d <= maxd; d++) {
        int sz = (int)arr[d].size() - 1;
        for (int i = 1; i <= sz; i++) {
            std::cerr << "depth = " << d << " dfn = " << func[d][i] << " val = " << arr[d][i] << '\n'; 
        }
    }

    Seg2D seg2d(maxd);
    seg2d.build(arr, func);

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int u, k;
            i64 x;
            std::cin >> u >> k >> x;

            // L = depth[u] + k, R = depth[u] + k, L2(dfn) = dfn[u], R2(dfn) = dfnR[u]
            if (depth[u] + k > maxd) {
                continue;
            }
            seg2d.add(depth[u] + k, dfn[u], dfnR[u], x);

            // u 的子树，depth[u] + k, val += x
        } else {
            int u;
            std::cin >> u;
            // 查询 u 的子树
            std::cout << seg2d.query(1, maxd, dfn[u], dfnR[u]) << '\n';
        }
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

/* -------------------  用   例  -------------------
int main() {
    int n = 3, m = 4;
    std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1, 0));
    // 随便初始化
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = i * 10 + j;

    Seg2D st(n, m);
    st.build(a);

    // 在第 2 行 [2,4] 上 +5
    st.add(2, 2, 4, 5);

    // 查询 (1..3, 2..3)
    cout << st.query(1, 3, 2, 3) << '\n';   // 输出示例
    return 0;
}
*/