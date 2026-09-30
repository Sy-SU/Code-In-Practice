#include <bits/stdc++.h>

using i64 = long long;

#define int long long

template<int MOD>
struct ModInt {
    /*
    using Z = ModInt<998244353>;

    int main() {
        Z a = 2, b = 3;
        cout << a + b << "\n";    // 5
        cout << a * b << "\n";    // 6
        cout << a / b << "\n";    // 2 * inv(3)
        cout << a.pow(10) << "\n"; // 1024
    }
    */

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

using Z = ModInt<998244353>;

constexpr i64 INF = 1e18;

template<class T>
struct Fenwick {
    /*
    树状数组维护单点加，区间和
    使用 Fenwick<i64> tree(a); 初始化树状数组
    单点加: tree.add(pos, val);
    区间和: tree.sum(l, r)
    */
    int n;
    std::vector<T> tr;

    Fenwick() {
        n = 0;
        tr.assign(n + 1, T());
    }

    explicit Fenwick(const std::vector<T> &a) {
        n = a.size() - 1;
        tr.assign(n + 1, T());
        if (n) {
            for (int i = 1; i <= n; ++i) {
                tr[i] += a[i];
                int j = i + (i & -i);
                if (j <= n) tr[j] += tr[i];
            }
        }
    }

    void add(int pos, const T &val) {
        for (int i = pos; i <= n; i += i & -i) {
            tr[i] += val;
        }
    }

    T prefix(int pos) {
        T res = T();
        for (int i = pos; i; i -= i & -i) {
            res += tr[i];
        }
        return res;
    }

    T sum(int l, int r) {
        if (l > r) {
            return T();
        }
        return prefix(r) - prefix(l - 1);
    }
};

constexpr int N = 2e5 + 10;

struct TREAP
{
    int root;
    int cnt;        // 节点的总数
    int node[N][2]; // 左右儿子
    int size[N];    // 第i个点的子树大小
    int copy[N];    // 第i个点的副本数量
    i64 val[N];     // 值
    int dat[N];     // 随机优先级
    void pushup(int id)
    {
        size[id] = size[node[id][0]] + size[node[id][1]] + copy[id];
    }
    int create(i64 v)
    {
        val[++cnt] = v;
        dat[cnt] = rand();
        size[cnt] = 1;
        node[cnt][0] = node[cnt][1] = 0; // 没有子节点
        copy[cnt] = 1;
        return cnt;
    }
    TREAP()
    {
        cnt = 0; // 初始状态一共两个点
        root = create(-INF), node[root][1] = create(INF);
        pushup(root);
    }
    void rotate(int &id, int d) // d = 0左旋，1右旋
    {
        int tmp = node[id][d ^ 1];
        node[id][d ^ 1] = node[tmp][d];
        node[tmp][d] = id, id = tmp;
        pushup(node[id][d]), pushup(id);
    }
    void insert(int &id, i64 v)
    { // 插入一个节点
        if (!id)
        {
            id = create(v);
            return;
        }
        if (v == val[id])
            copy[id]++;
        else
        {
            int d = v < val[id] ? 0 : 1;
            insert(node[id][d], v);
            if (dat[id] < dat[node[id][d]])
                rotate(id, d ^ 1);
        }
        pushup(id);
    }
    void remove(int &id, i64 v)
    {
        if (!id)
            return;
        if (v == val[id])
        {
            if (copy[id] > 1)
            {
                copy[id]--, pushup(id);
                return;
            }
            if (node[id][0] || node[id][1])
            {
                if (!node[id][1] || dat[node[id][0]] > dat[node[id][1]])
                {
                    rotate(id, 1);
                    remove(node[id][1], v);
                }
                else
                {
                    rotate(id, 0);
                    remove(node[id][0], v);
                }
                pushup(id);
            }
            else
                id = 0; // 本节点是叶子节点，直接删除
            return;
        }
        v < val[id] ? remove(node[id][0], v) : remove(node[id][1], v);
        pushup(id);
    }
    int get_rank(int id, i64 v)
    {
        if (!id)
            return 0;
        if (v == val[id])
            return size[node[id][0]];
        else if (v < val[id])
            return get_rank(node[id][0], v);
        else
            return size[node[id][0]] + copy[id] + get_rank(node[id][1], v);
    }
    i64 get_val(int id, int rk)
    {
        if (!id)
            return INF;
        if (rk <= size[node[id][0]])
            return get_val(node[id][0], rk);
        else if (rk <= size[node[id][0]] + copy[id])
            return val[id];
        else
            return get_val(node[id][1], rk - size[node[id][0]] - copy[id]);
    }
    i64 preelem(i64 v)
    {
        int id = root;
        i64 pre = -INF;
        while (id)
        {
            if (val[id] < v)
                pre = val[id], id = node[id][1];
            else
                id = node[id][0];
        }
        return pre;
    }
    i64 nextelem(i64 v)
    {
        int id = root;
        i64 next = INF;
        while (id)
        {
            if (val[id] > v)
                next = val[id], id = node[id][0];
            else
                id = node[id][1];
        }
        return next;
    }
} treap;

void solve() {
	int m;
	std::cin >> m;

	std::vector<i64> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::map<i64, int> idx;
	auto b = a;
	std::sort(b.begin() + 1, b.end());
	for (int i = 1; i <= m; i++) {
		idx[b[i]] = i;
	}

	std::vector<i64> h(m + 1);
	// SegmentTree<Info, Tag> trv(h), cnt(h);
	Fenwick<i64> trv(h), cnt(h);

	for (int i = 1; i <= m; i++) {
		trv.add(idx[a[i]], a[i]);
		cnt.add(idx[a[i]], 1);
		treap.insert(treap.root, a[i]);
		if (i <= 2) {
			continue;
		}

		int lo = 2, hi = i - 1;
		int ch = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			auto check = [&](int rkA) -> bool {
				// left >= right
				i64 preBV = treap.preelem(treap.get_val(treap.root, rkA + 1));
				i64 nxtBV = treap.nextelem(treap.get_val(treap.root, rkA + 1));

				int pind = idx[preBV], nind = idx[nxtBV];
				// l cnt.query(1, pind).sum * preBV - trv.query(1, pind).sum / cnt.query(1, pind).sum
				// r trv.query(nind, n).sum - cnt.query(nind, n).sum * nxtBV  /  cnt.query(nind, n).sum
				if ((cnt.sum(1, pind) * preBV - trv.sum(1, pind))
					>=
					 (trv.sum(nind, m) - cnt.sum(nind, m) * nxtBV)) {
					return 1;
				} else {
					return 0;
				}
			};

			if (check(mid)) {
				hi = mid - 1;
				ch = mid;
			} else {
				lo = mid + 1;
			}
		}

		int r1 = ch - 1, r2 = ch;
		if (r1 == 1) {
			i64 preBV2 = treap.preelem(treap.get_val(treap.root, r2 + 1));
			i64 nxtBV2 = treap.nextelem(treap.get_val(treap.root, r2 + 1));
			int pind2 = idx[preBV2], nind2 = idx[nxtBV2];
			int up2;
			if ((cnt.sum(1, pind2) * preBV2 - trv.sum(1, pind2)) * i 
				>=
				 (trv.sum(nind2, m) - cnt.sum(nind2, m) * nxtBV2) * i) {
				up2 = (cnt.sum(1, pind2) * preBV2 - trv.sum(1, pind2));
			} else {
				up2 = (trv.sum(nind2, m) - cnt.sum(nind2, m) * nxtBV2);
			}
			std::cout << up2 * Z(i - 2).inv() << '\n';
			continue;
		}
		i64 preBV1 = treap.preelem(treap.get_val(treap.root, r1 + 1));
		i64 nxtBV1 = treap.nextelem(treap.get_val(treap.root, r1 + 1));
		int pind1 = idx[preBV1], nind1 = idx[nxtBV1];

		i64 preBV2 = treap.preelem(treap.get_val(treap.root, r2 + 1));
		i64 nxtBV2 = treap.nextelem(treap.get_val(treap.root, r2 + 1));
		int pind2 = idx[preBV2], nind2 = idx[nxtBV2];

		i64 up1 = -1, up2 = -1;

		if ((cnt.sum(1, pind1) * preBV1 - trv.sum(1, pind1))
			>=
			 (trv.sum(nind1, m) - cnt.sum(nind1, m) * nxtBV1)) {
			up1 = (cnt.sum(1, pind1) * preBV1 - trv.sum(1, pind1));
		} else {
			up1 = (trv.sum(nind1, m) - cnt.sum(nind1, m) * nxtBV1);
		}

		if ((cnt.sum(1, pind2) * preBV2 - trv.sum(1, pind2))
			>=
			 (trv.sum(nind2, m) - cnt.sum(nind2, m) * nxtBV2)) {
			up2 = (cnt.sum(1, pind2) * preBV2 - trv.sum(1, pind2));
		} else {
			up2 = (trv.sum(nind2, m) - cnt.sum(nind2, m) * nxtBV2);
		}

		// std::cerr << "up1 = " << up1 << " " << "ch1 = " << ch - 1 << '\n';
		// std::cerr << "up2 = " << up2 << " " << "ch2 = " << ch << '\n';

		i64 u = -1;

		if (r1 == 1) {
			u = up2;
		} else {
			if (up1 <= up2) {
				u = up1;
			} else {
				u = up2;
			}	
		}

		// std::cerr << up1 << " " << dn1 << " " << up2 << " " << dn2 << '\n';

		// std::cerr << "ans = " << u << "/" << (i - 2) << '\n';
		std::cout << u * Z(i - 2).inv() << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}