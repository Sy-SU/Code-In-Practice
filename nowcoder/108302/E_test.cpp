#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N=2e5+10;
int a[N];

void solve() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;++j){
			int tmp = a[i]^a[j];
			int cnt=0;
			for(int j=0;j<31;++j)
			{
				if((tmp>>j)&1){
					cnt^=1;
					if(cnt%2==0)tmp-=1<<j;
				}
			}
			res += tmp;
		}
	}
	cout<<res<<endl;

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}