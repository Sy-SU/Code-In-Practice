#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> l(n + 1);
	std::vector<std::vector<int>> a;
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i];
		std::vector<int> h(l[i]);
		for (int j = l[i] - 1; j >= 0; j--) {
			std::cin >> h[j];
		}

		a.push_back(h);
	}

	std::vector<int> output;

	std::vector<int> help(n);
	for (int i = 0; i < n; i++) {
		help[i] = i;
	}

	do {
		std::vector<int> to;

		std::map<int, bool> vis;
		for (int i = 0; i < n; i++) {
			for (auto e : a[help[i]]) {
				if (!vis[e]) {
					vis[e] = 1;
					to.push_back(e);
				}
			}
		}

		if (output.empty()) {
			output = to;
		} else {
			for (int i = 0; i < (int)output.size(); i++) {
				if (output[i] > to[i]) {
					output = to;
					break;
				}
				if (output[i] < to[i]) {
					break;
				}
			}
		}
	} while (std::next_permutation(help.begin(), help.end()));

	for (auto o : output) {
		std::cout << o << " ";
	}
	std::cout << '\n';
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