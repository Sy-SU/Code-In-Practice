#include<iostream>  
#include<vector>
#include<map>   
#include<algorithm>
#include<queue>
using namespace std;
const int N=2e5+5;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
void solve()
{   
	int n,k;string s;
	cin>>n>>s;
	int cnt1=0,cnt0=0,len=1;
	vector<int>q1,q0;
	s.push_back('c');
	for(int i=0;i<n;i++){
		if(s[i]=='1')cnt1++;
		else cnt0++;
		if(s[i]!=s[i+1]){
			if(s[i]=='1'&&len>1)q1.push_back(len);
			else if(s[i]=='0'&&len>1) q0.push_back(len);
			len=1;
		}else len++;
	}
	int drt=abs(cnt1-cnt0),ans=drt;
	if(drt==0){
		cout<<0<<'\n';
		return ;
	}
	if(drt==1){
		cout<<3<<'\n';
		return ;
	}
	vector<int>goal;
	if(cnt1>=cnt0)goal=q1;
	else goal=q0;
	sort(goal.begin(),goal.end(),cmp);
	int l=0,r=0,ok=0;
	for(auto ele:goal)
	{
		l+=2;
		r+=ele;
		if(l<=drt&&r>=drt){
			ok=1;
			break;
		}else if(l>drt)break;
	}
	if(!ok)ans+=2;
	cout<<ans<<'\n';
}
signed main()
{
    int T=1;
    cin>>T;
    while(T--)solve();
}
/*
1
5
00100
*/
