#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 10;

int p[N];
i64 arr[N];

int tree[N];
int siz;

inline int lowbit(int x)
{
	return x & (-x);
}
void opAdd(int x, int k)
{
	// 区间加
	for (; x <= siz; x += lowbit(x))
		tree[x] += k;
}
void build()
{
	for (int i = 1; i <= siz; i++)
	{
		opAdd(i, arr[i]);
	}
}
int queryP(int x)
{
	i64 ans = 0;
	for (; x; x -= lowbit(x))
	{
		ans = ans + tree[x];
	}
	return ans;
}
int opGetSum(int l, int r)
{
	// 查询区间和
	return queryP(r) - queryP(l - 1);
}

/*
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> arr[i];
	}
	siz = n, build();
	for (int i = 1; i <= m; i++)
	{
		int op;
		i64 x, y;
		std::cin >> op >> x >> y;
		if (op == 1)
			opAdd(x, y); // 单点加
		else
			std::cout << opGetSum(x, y) << '\n'; // 区间求和
	}
*/

struct QUERY {
	int l, r, c;
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		tree[i] = arr[i] = 0;
	}

	siz = n, build();


	std::vector<QUERY> q;
	std::vector<std::pair<int, int>> need;
	for (int i = 1; i <= m; i++) {
		int l, r, c;
		std::cin >> l >> r >> c;
		q.push_back({l, r, c});
		l--;
		need.push_back({l, p[c] - 1}), need.push_back({r, p[c] - 1});
	}

	std::map<std::pair<int, int>, int> ans;

	std::sort(need.begin(), need.end());

	int ptr = 0;
	for (int i = 0; i <= n; i++) {
		if (i) {	
			opAdd(p[i], 1);
		}
		while (ptr < 2 * m && need[ptr].first == i) {
			ans[{i, need[ptr].second}] = opGetSum(1, need[ptr].second);
			// std::cerr << "ans:" << i << " " << need[ptr].second << " = " << opGetSum(1, need[ptr].second) << '\n';
			ptr++;
		}
	}

	for (const auto &[l, r, c] : q) {
		std::cout << l + ans[{r, p[c] - 1}] - ans[{l - 1, p[c] - 1}] << '\n';
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