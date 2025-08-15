#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
typedef long long ll;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
		f = (c == '-') ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9')
		x = x * 10 + c - 48, c = getchar();
	return f * x;
}
int val[1000010];
int a[1000010], n;
int lowbit(int x) { return x & (-x); }
void add(int x, int v) {
	while (x <= n)
		a[x] += v, x += lowbit(x);
}
int sum(int x) {
	int ans = 0;
	while (x)
		ans += a[x], x -= lowbit(x);
	return ans;
}
vector<int> s[1000010];
int b[1000010];
int Sum[1000010];
signed main() {
	int TT = 1;
	while (TT--) {
		n = read();
		for (int i = 1; i <= n; i++)
			val[i] = read(), s[val[i]].push_back(i), a[i] = 0;
		for (int i = 1; i <= n; i++)
			add(val[i], 1), b[i] = sum(n) - sum(val[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int A = 0, B = 0;
			int AA = 0, BB = 0;
			for (int j = 0; j < s[i].size(); j++) {
				int now = s[i][j];
				if (now % 2 == 0) {
					ans += (BB * b[now] - B);
					ans += 2 * (AA * b[now] - A);
					B += b[now], BB++;
				} else {
					ans += 2 * (BB * b[now] - B);
					ans += (AA * b[now] - A);
					A += b[now], AA++;
				}
			}
		}
		cout << ans << "\n";
	}
}