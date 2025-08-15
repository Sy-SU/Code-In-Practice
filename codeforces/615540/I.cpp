#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
constexpr int mod = 1e9 + 7;

i64 qpow(i64 a, int b, int mod) {
	i64 res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

i64 inv(int x) {
	return qpow(x, mod - 2, mod);
}

using PII = pair<int,int>;
void solve() {
	int n, k;
	std::cin >> n >> k;
	vector<PII> p(n + 1);
	for(int i=1;i<=n;++i)
	{
		int s, t;
		cin>> s >> t;
		p[i] = {s, t+s};
	}
	sort(p.begin() + 1,p.end());
	int lef = 1,rig = n;
	int ans = n;
	auto check=[&](int x)
	{
		int cnt = 0;
		multiset<int>st;
		for(int i=1;i<=n;++i)
		{
			int s = p[i].first, e = p[i].second;

			if(st.size()==x)
			{
				auto m = *st.begin();
				
				if(s+k<m){
					return 0;
				}
				else{	
					//*m = (e-s) + (*m);
					auto p = st.find(m);
					st.erase(p);
					st.insert((e-s)+max(m,s));
				}
			}
			else{
				st.insert(e);
			}
		}		
		return 1;
	};
	while(lef<=rig)
	{
		int mid = lef+rig>>1;
		//cout<<mid<<endl;
		if(check(mid))
		{
			rig = mid-1;
			ans = mid;
		}
		else lef = mid+1;
	}
	cout<<ans<<'\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}