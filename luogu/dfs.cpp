#include<bits/stdc++.h>

constexpr int N = 1e5 + 10; 

int main() {
    // ��������һ��һ������ n
	// ����������һ�� n ������ a_i
	// �� q ��ѯ��
	// ÿ�θ���һ������ x
	// ����Ҫ��� x �� ���������г��ֵĴ���
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
