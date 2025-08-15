#include <bits/stdc++.h>

using i64 = long long;
#define int long long
using namespace std;
int n;
const int N=2e5+10;
const int mod=1e9+7;
i64 qmi(i64 a,int b,int mod)
{
	i64 res = 1;
	while(b)
	{
		if(b&1)
		{
			res = res*a%mod;
		}
		b>>=1;
		a = a*a%mod;
	}
	return res;
}
i64 inv(int x)
{
	return qmi(x,mod-2,mod);
}
struct Node{
	int v, w;
};
vector<Node>e[N];
int son[N];
int dp[N];
void dfs(int u,int fa,int x)
{
	son[u]=1;
	for(auto&[v,w]:e[u])
	{
		if(v==fa)continue;
		dfs(v,u,w);
		son[u]+=son[v];	
	}
}
void dfs2(int u,int fa,int x)
{
	dp[u] = x;
	int sum = 0;
	for(auto&[v,w]:e[u])
	{
		if(v==fa)continue;
		dfs2(v,u,w);
		cout<<"fa: "<<fa<<" now:"<<u<<" son:"<<v<<" - "<<son[v]<<"/"<<son[u]<<"*"<<dp[v]<<'\n'; 
		dp[u] += (son[v]*inv(son[u])%mod*dp[v]%mod)*2%mod;
		sum += dp[v];
		dp[u]%=mod;
	}	
	cout<<"fa: "<<fa<<" now:"<<u<<" "<<sum<<'\n';
}
void solve() {
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		int fa,x,y;
		cin>>fa>>x>>y;
		int w = y*inv(x)%mod;
		//cout<<w<<"!\n";
		e[fa].push_back({i,w});
	}
	dfs(1, 0, 0);
	dfs2(1,0,0);
	for(int i=1;i<=n;++i)
	{
		cout<<i<<": "<<son[i]<<" "<<dp[i]<<'\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}