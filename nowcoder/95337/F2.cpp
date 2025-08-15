#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 7;

int n, q, k;

i64 a[N];
i64 arr[N];

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

struct NODE {
	int l, r;
	std::vector<i64> ans;
} node[4 * N];

std::vector<i64> merge(std::vector<i64> v1, std::vector<i64> v2) {
	std::vector<i64> res(k, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			res[(i + j) % k] = (res[(i + j) % k] + v1[i] * v2[j] % mod) % mod;
		}
	}
	return res;
}

void pushup(int u) {
	node[u].ans = merge(node[u << 1].ans, node[u << 1 | 1].ans);
}


void build(int u, int l, int r) {
	std::vector<i64> tmp(k, 0);
	tmp[0] = (a[l] - 1) * inv(a[l], mod) % mod;
	tmp[1] = inv(a[l], mod);
	node[u] = {l, r, tmp};
	// std::cerr << u << " " << (node[u].ans)[0] << '\n';
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

std::vector<i64> getsum(int u, int l, int r) {
	// 查询区间和
	if (l <= node[u].l && node[u].r <= r)
	{
		return node[u].ans;
	}
	int mid = (node[u].l + node[u].r) >> 1;
	std::vector<i64> res(k, 0);
	if (l <= mid && r <= mid) {
		res = getsum(u << 1, l, r);
	} else if (l > mid && r > mid) {
		res = getsum(u << 1 | 1, l, r);
	} else if (l <= mid && r > mid) {
		res = merge(getsum(u << 1, l, r), getsum(u << 1 | 1, l, r));
	} else {
		assert(0);
	}
	return res;
}

std::vector<i64> opGetSum(int l, int r) {
	return getsum(1, l, r);
}

void solve() {
	std::cin >> n >> q >> k;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	build(1, 1, n);

	while (q--) {
		int l, r, p;
		std::cin >> l >> r >> p;
		std::cout << opGetSum(l, r)[p] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}