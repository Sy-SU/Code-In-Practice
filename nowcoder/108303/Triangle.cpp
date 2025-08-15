#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
const int N=20;
int mat[N][N];
int n, m;
int cnt=0;
int ta[N][N];
void solve() {


	std::cin >> n;
    ta[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        ta[i][0] = 1;
        cout<<ta[i][0]<<" ";
        for(int j=1;j<=i;++j)
        {
            ta[i][j] = ta[i-1][j-1] + ta[i-1][j]; 
            cout<<ta[i][j]<<" ";
        }cout<<endl;
    }

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