#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&a[i-1]!=1&&a[i+1]!=1)
		{
			a[i]=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
 } 