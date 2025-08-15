#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

using PII = pair<int,int>;
void solve() {
	int n;
	cin>>n;
	set<PII>l,r;
	vector<int> fa(n+1);
	for(int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			l.insert({1,x});
			r.insert({-n,x});
			continue;
		}
		auto& pl = l.lower_bound(x);
		auto& pr = r.lower_bound(-x);
		int lef = pl.first,rig = -pr.first, val = pl.second;
		fa[x] = val;
		if(lef<val&&rig>val)
		{
			if(x<val)
			{
				pl.second = x;
				pr.insert({1-val,x});
			}
			else{
				pr.second = x;
				pl.insert({val+1,x});
			}
		}
		else if(lef<val)
		{
			pl.second = x;
			pr.second = x;
		}
		else{
			pl.second = x;
			pr.second = x;
		}
	}
	for(int i=1;i<=n;++i)
	{
		cout<<i<<" "<<fa[i]<<endl;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
