#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvii vector<vector<pair<int,int>>>
#define vvll vector<vector<pair<ll,ll>>>
#define vst vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mkunique(x) sort(all(x));(x).erase(unique(all(x)),(x).end())
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=15<<26;

vector<pair<int,int>> G[MAX];
bool visited[2*MAX];

void DFS(int u, vector<int> &trail) {
    while(!G[u].empty()) {
        int v=G[u].back().fi,id=G[u].back().se;
        G[u].pop_back();
        
        if(visited[id]) continue;
        
        visited[id]=1;
        
        DFS(v,trail);
    }
    trail.push_back(u);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        ll need=N-1;
        ll K;
        for(ll s=1;;s++){
            ll can=s;
            if(s%2==0){
                can+=s*(s-2)/2+1;
            }else{
                can+=s*(s-1)/2;
            }
            if(can>=need){
                K=s;
                break;
            }
        }
        
        for(int i=0;i<2000;i++){
            G[i].clear();
            visited[i]=0;
        }
        
        if((K&1)||K==2){
            int t=0;
            for(int i=0;i<K;i++){
                for(int j=i;j<K;j++){
                    G[i].pb(mp(j,t));
                    G[j].pb(mp(i,t));
                    t++;
                }
            }
        }else{
            int t=0;
            for(int i=0;i<K;i++){
                for(int j=i;j<K;j++){
                    if(i%2==0&&i+1==j&&i>=2) continue;
                    G[i].pb(mp(j,t));
                    G[j].pb(mp(i,t));
                    t++;
                }
            }
        }
        vi res;
        DFS(0,res);
        
        vl ans;
        
        vl S;
        for(int a=0;a<=K-1;a++){
            ll x=1;
            for(int i=1;i<=a;i++) x*=2;
            for(int i=1;i<=K-1-a;i++) x*=3;
            S.pb(x);
        }
        
        for(int i=0;i<N;i++) ans.pb(S[res[i]]);
        
        std::set<ll> stt;


        for(int i=0;i<N;i++){
            // cout<<ans[i]<<" ";
            stt.insert(ans[i]);
        }
        std::cerr << stt.size() << '\n';
        // cout<<"\n";
    }
}


