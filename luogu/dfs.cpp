#include<bits/stdc++.h>

constexpr int N = 1e5 + 10; 

int main() {
    // 首先输入一行一个整数 n
	// 接下来输入一行 n 个整数 a_i
	// 有 q 次询问
	// 每次给出一个整数 x
	// 你需要输出 x 在 上述序列中出现的次数
	int n;
	std::cin >> n;
	std::map<long long, int> cnt;
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		cnt[x]++;
	}	 
	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		std::cout << cnt[x] << '\n';
	}
	
    return 0;
}
