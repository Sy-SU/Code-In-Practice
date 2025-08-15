#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
constexpr int mod = 1e9 + 7;
const int N=1e6+10;
const int P=131;
int p[N];
void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<std::string>> vec(n + 1, std::vector<std::string>(2));
	for (int i = 1; i <= n; i++) {
		std::cin >> vec[i][0];
		vec[i][1] = vec[i][0];
		std::reverse(vec[i][1].begin(), vec[i][1].end());
	}
	p[0]=1;
	for(int i=1;i<=1e6;++i)
	{
		p[i]=p[i-1]*P%mod;
	}
	std::vector<std::vector<int>>h(n+1),rh(n+1);
	for (int i = 1; i <= n; i++) {
			int sz = vec[i][0].size();
			h[i]=vector<int>(sz+1);
			for(int j=1;j<=sz;++j){
				h[i][j]=h[i][j-1]*P%mod+vec[i][0][j-1];
				h[i][j]%=mod;
			}
			sz = vec[i][1].size();
			rh[i]=vector<int>(sz+1);
			for(int j=1;j<=sz;++j){
				rh[i][j]=rh[i][j-1]*P%mod+vec[i][1][j-1];
				rh[i][j]%=mod;
			}
	}

	auto hash = [&](int index, int l, int r) -> i64 {
		i64 res = ((h[index][r] - h[index][l - 1] * p[r - l + 1]%mod)%mod+mod)%mod;
		//cout<<res<<" "<<index<<" "<<r-l+1<<endl;
		return res;
	};
	auto rhash = [&](int index, int l, int r) -> i64 {
		i64 res = ((rh[index][r] - rh[index][l - 1] * p[r - l + 1]%mod)%mod+mod)%mod;
		//cout<<res<<" "<<index<<" "<<r-l+1<<endl;
		return res;
	};
	while (m--) {
		int a, b;
		std::cin >> a >> b;
		int sz1 = vec[a][0].size(),sz2 = vec[b][0].size();
		int lef=0,rig=min(sz1,sz2);
		int ans=0;
		while(lef<=rig)
		{
			int mid = lef+rig>>1;
			if(hash(a,1,mid)==rhash(b,1,mid))
			{
				lef=mid+1;
				ans=mid;
			}
			else{
				rig=mid-1;
			}
		}
		cout<<ans<<'\n';
	}

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	//std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}