#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 10;

i64 arr[N];

i64 TreeArray_tree[N];
int TreeArray_siz;

inline int lowbit(int x)
{
	return x & (-x);
}
void TreeArray_opAdd(int x, i64 k)
{
	// 区间加
	for (; x <= TreeArray_siz; x += lowbit(x))
		TreeArray_tree[x] += k;
}
void TreeArray_build()
{
	for (int i = 1; i <= TreeArray_siz; i++)
	{
		TreeArray_opAdd(i, arr[i]);
	}
}
i64 TreeArray_queryP(int x)
{
	i64 ans = 0;
	for (; x; x -= lowbit(x))
	{
		ans = ans + TreeArray_tree[x];
	}
	return ans;
}
i64 TreeArray_opGetSum(int l, int r)
{
	// 查询区间和
	return TreeArray_queryP(r) - TreeArray_queryP(l - 1);
}

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	} 

	for (int i = 1; i <= n; i++) {
		arr[i] = 0;
	}

	TreeArray_siz = n, TreeArray_build();

	int ans = 0;
	int l = -1, r = -1;

	int sz = 0;
	for (int i = 1; i <= n; i++) {
		sz++;

		TreeArray_opAdd(a[i], 1);

		int lo = 1, hi = n;
		int med = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (TreeArray_opGetSum(1, mid) >= sz / 2) {
				lo = mid + 1;
				med = mid;
			} else {
				hi = mid - 1;
			}
		}

		if (sz >= k) {
			if (ans < med) {
				ans = med;
				l = i - sz + 1, r = i;
			}
		}
		while (sz > k) {
			int lft = i - sz + 1;
			if (med > a[lft]) {
				TreeArray_opAdd(a[lft], -1);
				sz--;				
			} else {
				break;
			}
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