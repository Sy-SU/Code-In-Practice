#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

vector<int> edge[N];

int depth[N];

void dfs(int u, int fa) {
	// u ��ʾ��ǰ���ʵ��Ľڵ�
	// fa ��ʾ u �ĸ��ڵ�
	for (int v : edge[u]) {
		if (v != fa) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	} 
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << i << " �����Ϊ " << depth[i] << '\n';
	}
	return 0;
}
/*
10
1 2
1 3
2 4
2 5
2 6
3 7
3 8
7 9
7 10
*/

