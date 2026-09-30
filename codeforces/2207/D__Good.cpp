#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=1e18;
vector<ll> E[500010];
ll n,k,root,f[500010],vis[500010];
void dfs(ll u,ll fa)
{
    ll minnum1=inf,minnum2=inf,flag=0;
    for(auto v:E[u])
    {
        if(v!=fa)
        {
            dfs(v,u);
            flag=1;
            //if(u==4)
                //printf("??? %lld %lld %lld\n",f[v],minnum1,minnum2);
            if(f[v]<minnum1)
                minnum2=minnum1,minnum1=f[v];
            else    if(f[v]<minnum2)
                minnum2=f[v];
        }
    }
    if(!flag)
        f[u]=0,vis[u]=1;
    else
    {
        if(minnum1+minnum2+2<=k+1)
            vis[u]=1,f[u]=0;
        else
            f[u]=minnum1+1;
    }
   // printf("??? %lld %lld %lld %lld\n",u,minnum1,minnum2,f[u]);
    return;
}
int main()
{
    ll i,u,v,T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&k,&root);
        for(i=1;i<n;++i)
        {
            scanf("%lld %lld",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(root,0);
        if(vis[root])
            printf("YES\n");
        else
            printf("NO\n");
        for(i=1;i<=n;++i)
        {
            vis[i]=f[i]=0;
            E[i].clear();
        }
    }
    return 0;
}