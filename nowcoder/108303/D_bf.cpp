#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
const int N=10;
int mat[N][N];
int n, m;
int cnt=0;
void dfs(int i, int n)
{
    int h = i/n,l = i%n;
    //cout<<h<<" "<<l<<endl;
    if(i==n*n)
    {
        ++cnt;
        /*
        cout<<"-------------------\n";
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        return;
    }
    
    if(l == 0)
    {
        mat[h][l] = 0;
        dfs(i+1,n);
    }
    else{
        int up = m;
        if(h)
        {
            up = min(up, mat[h][l-1]+mat[h-1][l]-mat[h-1][l-1]);
            //if(h==1)cout<<up<<endl;
        }
        for(int k=mat[h][l-1]; k<=up;++k)
        {
            mat[h][l]=k;
            dfs(i+1,n);
            mat[h][l]=0;
        }
    }
}
void solve() {


	std::cin >> n >> m;
    dfs(0, n);
    cout<<"-----------------\n";
    cout<<cnt<<endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	//std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}