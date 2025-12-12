#include<bits/stdc++.h>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ld eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;
const ll INFF=0x3f3f3f3f3f3f3f3f;

const int N=2500006;
struct Node
{
    int l,r;
    int val;
    int id;
    int add;
}tr[4*N];
int ac,dr;
int a[N],d[N];
int s[N];
int n;
void pushup(Node &root,Node &left,Node &right)//Todo
{
    // root.maxi=max(left.maxi,right.maxi);
    if(left.val<0) root.val=left.val,root.id=left.id;
    else if(right.val<0) root.val=right.val,root.id=right.id;
    else root.val=0;
}
void pushup(int u)
{
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void pushdown(int u)//Todo
{
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if(root.add)
    {
        left.val+=root.add;
        left.add+=root.add;
        right.val+=root.add;
        right.add+=root.add;
        root.add=0;
    }
}
void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r)//Todo
    {
        // tr[u].maxi=-l;
        if(l==0) tr[u].val=-l;
        else tr[u].val=s[l-1]-l;
        tr[u].id=l;
    }
    else
    {
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int c)
{
    if(tr[u].l>=l&&tr[u].r<=r)//Todo
    {
        tr[u].val+=c;
        tr[u].add+=c;
        return ;
    }
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(l<=mid) modify(u<<1,l,r,c);
    if(r>mid) modify(u<<1|1,l,r,c);
    pushup(u);
}
Node query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)//Todo
    {
        return tr[u];
    }
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(r<=mid) return query(u<<1,l,r);
    else if(l>mid) return query(u<<1|1,l,r);
    else
    {
        Node res;
        Node left=query(u<<1,l,r);
        Node right=query(u<<1|1,l,r);
        pushup(res,left,right);
        return res;
    }
}

int f(int ai,int di)
{
    return max(ai-ac,0)+max(di-dr,0);
}
int main()
{
    scanf("%d%d",&ac,&dr);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);

    for(int i=1;i<=n;i++) s[f(a[i],d[i])]++;
    for(int i=1;i<N;i++) s[i]+=s[i-1];

    build(1,0,N-1);

    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int k,ak,dk;
        scanf("%d%d%d",&k,&ak,&dk);

        int las=f(a[k],d[k]);
        a[k]=ak;
        d[k]=dk;
        int now=f(a[k],d[k]);
        modify(1,las+1,N-1,-1);
        modify(1,now+1,N-1,1);

        auto res=query(1,0,N-1);
        int id=res.id;
        int ans=res.val+id;
        printf("%d\n",ans);
    }
}