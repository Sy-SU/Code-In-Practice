#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

int dis[N];
bool inq[N];

void solve() {
	int n;
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
	}
	
	dis[1] = 0;
	std::queue<int> q;
	q.push(1);
	inq[1] = 1;
	
	while (!q.empty()) {
		int now = q.front();
		std::cerr << now << '\n';
		q.pop();
		inq[now] = 0;
		
		int tox;
		tox = now - 1;
		if (1 <= tox && tox <= n) {
			if (dis[tox] > dis[now] + 1) {
				dis[tox] = dis[now] + 1;
				if (!inq[tox]) {
					q.push(tox);
					inq[tox] = 1;
				}
			}
		}
		
		tox = now + 1;
		if (1 <= tox && tox <= n) {
			if (dis[tox] > dis[now] + 1) {
				dis[tox] = dis[now] + 1;
				if (!inq[tox]) {
					q.push(tox);
					inq[tox] = 1;
				}
			}
		}
		
		tox = now * 2;
		if (1 <= tox && tox <= n) {
			if (dis[tox] > dis[now] + 1) {
				dis[tox] = dis[now] + 1;
				if (!inq[tox]) {
					q.push(tox);
					inq[tox] = 1;
				}
			}
		}
	}
	std::cout << dis[n] << '\n'; 
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
