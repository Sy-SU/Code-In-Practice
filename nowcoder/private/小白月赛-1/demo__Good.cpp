#include <bits/stdc++.h>
using namespace std;

/* ---------- 常量与类型 ---------- */
using U32 = uint32_t;                   // 32-bit 无符号
const U32 FULL = (1u << 26) - 1;        // 低 26 位全 1 掩码

/* ---------- 线段树 ---------- */
struct SegTree {
    struct Node { U32 mask; uint8_t lazy; };

    int n;
    vector<Node> tr;

    explicit SegTree(const string &s) {
        n = (int)s.size();
        tr.resize(n << 2);
        build(1, 1, n, s);
    }

    /* 循环左移 d (0‥25) */
    static inline U32 rot(U32 m, int d) {
        if (d == 0) return m;
        return ((m << d) | (m >> (26 - d))) & FULL;
    }

    /* ---------- build / push ---------- */
    void build(int p, int l, int r, const string &s) {
        tr[p].lazy = 0;
        if (l == r) {
            tr[p].mask = 1u << (s[l - 1] - 'a');     // ⚠️ 记得 1u
            std::cerr << "tree" << p << " " << s[l - 1] << " " << tr[p].mask << '\n';
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, s);
        build(p << 1 | 1, mid + 1, r, s);
        pull(p);
    }
    inline void pull(int p) { tr[p].mask = tr[p<<1].mask ^ tr[p<<1|1].mask; }

    inline void apply(int p, int d) {                 // 对节点打标记
        tr[p].mask = rot(tr[p].mask, d);
        tr[p].lazy = uint8_t((tr[p].lazy + d) % 26);
    }
    inline void push(int p) {
        uint8_t d = tr[p].lazy;
        if (!d) return;
        apply(p << 1    , d);
        apply(p << 1 | 1, d);
        tr[p].lazy = 0;
    }

    /* ---------- 区间操作 ---------- */
    void range_rot(int L,int R,int d){ range_rot(1,1,n,L,R,d); }
    U32  range_mask(int L,int R){ return range_mask(1,1,n,L,R); }

private:
    void range_rot(int p,int l,int r,int L,int R,int d){
        if(L<=l && r<=R){ apply(p,d); return; }
        push(p);
        int mid=(l+r)>>1;
        if(L<=mid) range_rot(p<<1,l,mid,L,R,d);
        if(R >mid) range_rot(p<<1|1,mid+1,r,L,R,d);
        pull(p);
    }
    U32 range_mask(int p,int l,int r,int L,int R){
        std::cerr << p << " " << l << " " << r << " " << L << " " << R << '\n';
        if(L<=l && r<=R) return tr[p].mask;
        push(p);
        int mid=(l+r)>>1; U32 res=0;
        if(L<=mid) res ^= range_mask(p<<1,l,mid,L,R);
        if(R >mid) res ^= range_mask(p<<1|1,mid+1,r,L,R);
        return res;
    }
};

/* ---------- 处理一组数据 ---------- */
void solve() {
    int n, q;  cin >> n >> q;
    string s;  cin >> s;

    SegTree seg(s);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; long long d; cin >> l >> r >> d;
            seg.range_rot(l, r, int(d % 26));         // ⚠️ 取模后转 int
        } else {                                      // op == 2
            int l, r; cin >> l >> r;
            U32 m = seg.range_mask(l, r);
            std::cerr << m << '\n';
            int odd = __builtin_popcount(m);          // C++20 可用 std::popcount
            cout << (odd <= 1 ? "YES\n" : "NO\n");
        }
    }
}

/* ---------- 主函数，支持多组 ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    if (!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}
