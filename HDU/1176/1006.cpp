#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	i64 del, res;
};

void solve() {
	int n, p;
	i64 k, m;
	std::cin >> n;
	int res = 0, sum = 0;
	bool cld = 0;
	for(int i=1;i<=n;++i)
	{
		int k, op;
		std::cin>>k>>op;
		if(op){
			//path
			if(k == 2) res^=1;
			else{
				//res ^= 1;
				bool t = 1;
				cld ^= t;

			}
		}
		else{
			// circle - ok 
			if(k == 3) res ^=1;
			else if(k == 4);
			else{
				//res ^= 1;
				int rest = k - 3;
				bool t = 1;
				cld ^= t;
			}

		}
	}
	std::cout<<(cld||res?"Yes":"No")<<'\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}