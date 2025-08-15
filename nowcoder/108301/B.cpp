#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
constexpr int N = 2e5 + 10;
using PII = pair<int,int>;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,k;
bool check(int x,int y, int r = m)
{
	return x>=1&&x<=n&&y>=1&&y<=r;
}
void bfs(PII s, auto& vis, auto& mat)
{
	queue<PII>q;
	q.push(s);
	vis[s.first][s.second]=1;
	while(q.empty()==0)
	{
		auto [x,y] = q.front();
		q.pop();
		//cout<<x<<" "<<y<<endl;
		for(int i=0;i<4;++i)
		{
			if(dx[i]==0&&dy[i]==1)continue;
			int nx = x+dx[i],ny=y+dy[i];
			if(check(nx,ny)&&!vis[nx][ny]&&mat[nx][ny]=='0')
			{
				vis[nx][ny]=1;
				q.push({nx,ny});
			}
		}
	}

}

void solve() {
	cin>>n>>m>>k;
	vector<string>mat(n+1);
	vector<vector<int>>visen(n+1,vector<int>(m+1));
	vector<vector<int>>visst(n+1,vector<int>(m+1));
	for(int i=1;i<=n;++i)
	{
		cin>>mat[i];
		mat[i]=' '+mat[i];
	}
	PII st = {1,1};
	PII en = {1,m};
	bfs(en,visen,mat);
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<visen[i][j]<<" ";
		}cout<<endl;
	}
	*/
	//return;
	queue<PII>q;
	visst[st.first][st.second]=1;
	queue<PII>tmp;
	tmp.push(st);
	for(int i=1;i<=m-k;++i)
	{
		int r = i+k;
		q = tmp;
		while(tmp.size())tmp.pop();
		while(q.empty()==0)
		{
			auto [x,y] = q.front();
			q.pop();
			//cerr<<x<<" "<<y<<endl;
			if(y==r && r < m && visen[x][y]==0){
				cout<<"Yes\n";return;
			}
			if(y==r)
			{
				tmp.push({x,y});
			}
			for(int i=0;i<4;++i)
			{
				if(dx[i]==0&&dy[i]==-1)continue;
				int nx = x+dx[i],ny=y+dy[i];
				if(check(nx,ny,r)&&!visst[nx][ny]&&mat[nx][ny]=='0')
				{
					visst[nx][ny]=1;
					q.push({nx,ny});
				}
			}
		}
		/*
		cout<<i<<endl;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				cout<<visst[i][j]<<" ";
			}cout<<endl;
		}
		*/
	}
	cout<<"No\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	solve();

	return 0;
}