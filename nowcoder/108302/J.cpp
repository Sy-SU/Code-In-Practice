#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
int n,m;
using PII = pair<int,int>;
struct Node{
	int x,y,d;
};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void solve() {
	cin>>n>>m;
	vector<vector<int>> mat(n+1,vector<int>(m+1));
	auto vis = mat;
	auto vis1 = vis;
	queue<Node>q;
	bool f=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j){
			cin>>mat[i][j];
			if(mat[i][j])q.push({i,j,0}),f=1;
		}
	}
	vector<Node>ord;
	while(q.empty()==0)
	{
		auto [x,y,d] = q.front();
		q.pop();
		if(vis1[x][y])continue;
		if(!mat[x][y])
			ord.push_back({x,y,d});
		vis1[x][y]=1;
		//cout<<x<<" "<<y<<" "<<d<<"!"<<endl;
		for(int i=0;i<4;++i)
		{
			int nx = x+dx[i], ny = y+dy[i];
			//cout<<nx<<" "<<ny<<"in"<<endl;
			if(nx<1 || nx>n || ny<1 || ny>m)continue;
			if(vis1[nx][ny])continue;
			//cout<<nx<<" "<<ny<<"in"<<endl;
			q.push({nx,ny,d+1});
		}
	}
	//cout<<ord.size()<<endl;

	auto check=[&](int lim){
		vector<PII>tmp;
		int dx = 1e9, ux = -1e9,dy = 1e9, uy = -1e9;
		for(auto& [x,y,d]:ord)
		{
			if(d>lim)
			{
				dx = min(dx,x-y);
				ux = max(ux,x-y);
				dy = min(dy,x+y);
				uy = max(uy,x+y);
				tmp.push_back({x-y,x+y});
			}
		}
		//cout<<lim<<" "<<ux<<" "<<dx<<" : "<<uy<<" "<<dy<<endl; 
		return max((ux-dx),(uy-dy))<=2*lim;
	};
	if(f==0){
		cout<<n/2+m/2<<endl;return;
	}
	int lef = 0,rig = n+m;
	int ans = -1;
	while(lef<=rig)
	{
		int mid = lef+rig>>1;
		if(check(mid)){
			ans = mid;
			rig = mid-1;
		}
		else lef=mid+1;
	}
	cout<<ans<<endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}