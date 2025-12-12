#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define int long long

void solve()
 {
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c.begin(),c.end());
	vector<int> ans(n);

	int maxans = -2e18;
	do
	{
		for (int i = 0; i < n; i++) {
			ans[i] = a[i] * c[i] + b[i];
		}
		sort(ans.begin(),ans.end());
		maxans = std::max(maxans, ans[n / 2]);
	}while(next_permutation(c.begin() + 1,c.end()));
	std::cout << maxans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}