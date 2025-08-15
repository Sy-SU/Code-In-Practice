#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
using namespace std;
void solve() {
	int n;
	std::cin >> n;
	vector<int>nums;
	int to = n;
	while(to){
		nums.push_back(to);
		to>>=1;
		nums.push_back(-to);
		nums.push_back(-to);
	}
	for(auto &v:nums)cout<<v<<" ";
	cout<<endl;
	int len = nums.size();
	vector<vector<int>> mat(len+1,vector<int>(len+1));
	for(int i=1;i<=len;++i)
	{
		mat[i][i]=1;
		mat[i].back() = nums[i-1];
	}
	for(int i=1;i<=len;++i)
	{
		for(int j=1;j<=len;++j)cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	for(int i=1;i<=len;++i)
	{
		if(len%3==1)
		{
			add(i,i+1,i+2);
		}
		else{
			int nxt = i;
			add()
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}