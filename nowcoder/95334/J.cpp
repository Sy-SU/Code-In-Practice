#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, h, m;
	std::cin >> n >> h >> m;

	std::set<std::string> tran, nap, sleep;

	for (int i = 1; i <= n; i++) {
		std::string id;
		std::cin >> id;
		int year, month, day;
		scanf("%d-%d-%d", &year, &month, &day);
		int hour, minu, seco;
		scanf("%d:%d:%d", &hour, &minu, &seco);

		if (h != year || m != month) {
			continue;
		}

		if (hour >= 7 && hour <= 8) {
			tran.insert(id);
		} 
		if (hour == 9 && minu == 0 && seco == 0) {
			tran.insert(id);
		}

		if (hour >= 11 && hour <= 12) {
			nap.insert(id);
		}
		if (hour == 13 && minu == 0 && seco == 0) {
			nap.insert(id);
		}

		if (hour >= 18 && hour <= 19) {
			tran.insert(id);
		}
		if (hour == 20 && minu == 0 && seco == 0) {
			tran.insert(id);
		}

		if (hour >= 22 && hour <= 23) {
			sleep.insert(id);
		}
		if (hour == 0) {
			sleep.insert(id);
		}
		if (hour == 1 && minu == 0 && seco == 0) {
			sleep.insert(id);
		}
	}
	std::cout << tran.size() << " " << nap.size() << " " << sleep.size() << '\n';
}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	solve();

	return 0;
}