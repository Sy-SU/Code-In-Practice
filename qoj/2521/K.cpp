#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] %= 4;
	}

	int cnt[4] = {0};
	std::vector<std::vector<int>> op(4);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		op[a[i]].push_back(i);
	}

	if (cnt[1] >= cnt[3]) {
		if ((cnt[1] - cnt[3]) / 2 > cnt[2]) {
			std::cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < cnt[3]; i++) {
			std::cout << op[3][i] << " " << op[1][i] << " ";
		}
		int ind = 0;
		for (int i = cnt[3]; i < cnt[1]; i += 2) {
			std::cout << op[2][ind++] << " " << op[1][i] << " " << op[1][i + 1] << " ";
		}
		for (int i = ind; i < cnt[2]; i++) {
			std::cout << op[2][i] << " ";
		}
		for (int i = 0; i < cnt[0]; i++) {
			std::cout << op[0][i] << " ";
		}
		std::cout << '\n';
	} else {
		if ((cnt[3] - cnt[1]) / 2 > cnt[2]) {
			std::cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < cnt[1]; i++) {
			std::cout << op[3][i] << " " << op[1][i] << " ";
		}
		int ind = 0;
		for (int i = cnt[1]; i < cnt[3]; i += 2) {
			std::cout << op[3][i] << " " << op[3][i + 1] << " " << op[2][ind++] << " ";
		}
		for (int i = ind; i < cnt[2]; i++) {
			std::cout << op[2][i] << " ";
		}
		for (int i = 0; i < cnt[0]; i++) {
			std::cout << op[0][i] << " ";
		}
		std::cout << '\n';
	}
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