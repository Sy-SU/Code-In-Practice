#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MAXN 1000010
#define debug cout<<"&"<<endl
int b[MAXN];
int a[MAXN]; 
int tr[MAXN];
int n;
int p[MAXN];
inline int lowbit(int x){
    return x&-x;
}
void add(int x,int v){
    for(int i=x;i<=2*n;i+=lowbit(i))tr[i]+=v;
}
int query(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i))ans+=tr[i];
    return ans;
        
}
struct node{
    int l,r,x;
}q[MAXN];
bool cmp(node a,node b){
    return a.r<b.r;
}
void solve(){
// 	int n;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    unordered_map<int,int>mp;
    for(int i=1;i<=2*n;i++)b[i]=b[i-1]+a[i];
    int cnt=0;
    for(int i=1;i<=2*n;i++){
        if(mp[a[i]])q[++cnt]={mp[a[i]],i,b[i]-b[mp[a[i]]-1]};
        else mp[a[i]]=i;
    }
    sort(q+1,q+1+n,cmp);
    mp.clear();
    for(int i=1;i<=n;i++){
    	mp[q[i].r]=q[i].x;
	}
    int ans=0;
    int tt=0;
    for(int i=1;i<=n;i++){
    	int cn=query(q[i].r)-query(q[i].l);
    	if(cn<q[i].x){
    		add(q[i].r,q[i].x-cn);
            ans+=q[i].x-cn;
        }
    }
    cout<<ans;
}
signed main(){
	ios;
	int t=1;
// 	cin>>t;
	while(t--)
	solve();
	return 0;
} 
