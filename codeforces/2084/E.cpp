#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int t[100005], v[100005];
int tt[100005];
vector<int> child[100005];
int arr[200005];
int len = 0;
int dp[20005][2005];
int siz[100005];
int tree[200005 * 5];
int ss;
int tcnt = 0;

void insert(int root, int l, int r, int target) {
	if(l == r) {
		tree[root] += 1;
		return;
	}
	int mid = (l + r) / 2;
	if(target <= mid) {
		insert(root * 2, l, mid, target);
	} else {
		insert(root * 2 + 1, mid + 1, r, target);
	}
	tree[root] = tree[root * 2] + tree[root * 2 + 1];
	return;
}

void dele(int root, int l, int r, int target) {
	if(l == r) {
		tree[root] -= 1;
		return;
	}
	int mid = (l + r) / 2;
	if(target <= mid) {
		dele(root * 2, l, mid, target);
	} else {
		dele(root * 2 + 1, mid + 1, r, target);
	}
	tree[root] = tree[root * 2] + tree[root * 2 + 1];
	return;
}

int Rank(int root, int l, int r, int target) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) / 2;
	if(tree[root * 2] >= target) {
		return Rank(root * 2, l, mid, target);
	} else {
		return Rank(root * 2 + 1, mid + 1, r, target - tree[root * 2]);
	}
	return -1;
}

/******************************************
  int count() {
  int l = 0, r = 1000000000, mid;
  while(l < r) {
  int cnt = 0;
  mid = (l + r) / 2;
  for(int i = 1; i <= len; i++) {
  if(mid >= arr[i]) cnt++;
  }
  if(cnt <= len / 2) l = mid + 1;
  else r = mid;
  }
  return l;
  }
 ******************************************/

void dfs1(int x, int fa) {
	int k = lower_bound(tt + 1, tt + ss + 1, t[x]) - tt;
	//    int k = mp[t[x]];
	insert(1, 1, ss + 5, k);
	++len;
	//    cout << x << ' ' << k << ' ' << Rank(1, 1, 200000, len / 2 + 1) << endl;
	v[x] = tt[Rank(1, 1, ss + 5, len / 2 + 1)];
//	siz[x] = 1;
	for(auto y: child[x]) {
		if(y == fa) continue;
		dfs1(y, x);
//		siz[x] += siz[y];
	}
	len--;
	dele(1, 1, ss + 5, k);
	return;
}

void dfs2(int x, int fa) {
	if(tcnt >= 1000000000) return;
	dp[x][1] = v[x];
	siz[x] = 1;
	for(auto y: child[x]) {
		if(y == fa) continue;
		dfs2(y, x);
		for(int i = min(siz[x], m); i != 0; i--) {
			for(int j = 1; j <= siz[y] && i + j <= m; j++) {
				dp[x][i + j] = max(dp[x][i + j], dp[x][i] + dp[y][j]);
//				tcnt++;
			}
		}
		siz[x] += siz[y];
	}
	return;
}

void test() {
	cout << "teeeeeeeeeeeeeest" << endl;
	for(int i = 1; i <= n; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	cout << "teeeeeeeeeeeeeest" << endl;
	return;
}

signed main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> t[i];
		tt[i] = t[i];
	}
	sort(tt + 1, tt + n + 1);
	ss = unique(tt + 1, tt + n + 1) - tt - 1;
	for(int i = 1, a, b; i <= n - 1; i++) {
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	//    test();
	long long ans = 0;
	for (int i = 0; i <= m; i++) {
		ans = max(ans, dp[1][i]);
	}
	cout << ans << endl;
	return 0;
}