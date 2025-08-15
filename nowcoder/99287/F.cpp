#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

i64 a[N];

i64 tree[N];
int siz;

inline int lowbit(int x)
{
    return x & (-x);
}
void opAdd(int x, i64 k)
{
    for (; x <= siz; x += lowbit(x))
        tree[x] += k;
}
void build()
{
    for (int i = 1; i <= siz; i++)
    {
        opAdd(i, a[i]);
    }
}
i64 queryP(int x)
{
    i64 ans = 0;
    for (; x; x -= lowbit(x))
    {
        ans = ans + tree[x];
    }
    return ans;
}

i64 opGetSum(int l, int r)
{
    return queryP(r) - queryP(l - 1);
}

std::vector<int> map[N];
int lst[N], pre[N];

int cnt0[N], cnt1[N];

void solve() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// build();
	siz = n;

	i64 ans = 0;

	for (int i = 1; i <= n; i++) {
		opAdd(a[i], 1);
		pre[i] = opGetSum(a[i] + 1, n);

		if (lst[a[i]] == 0) {
			lst[a[i]] = i;
		} else {
			int cnt = pre[i] - pre[lst[a[i]]];
			std::cerr << pre[i] << " " << pre[lst[a[i]]] << " " << lst[a[i]] << '\n';
			std::cerr << cnt << " " << cnt0[a[i]] << " " << cnt1[a[i]] << '\n';
			if (i % 2 == 1){
				ans += cnt * 1ll * (cnt0[a[i]] * 2 + cnt1[a[i]]);
			} else {
				ans += cnt * 1ll * (cnt0[a[i]] + cnt1[a[i]] * 2);
			}
			lst[a[i]] = i;
		}

		cnt0[a[i]] += (i % 2 == 0);
		cnt1[a[i]] += (i % 2 == 1);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}