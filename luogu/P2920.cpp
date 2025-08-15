#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE
{
	int sta, len;
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<NODE> node(n + 1);
	for (int i = 1; i <= n; i++) {
		int t, s;
		std::cin >> t >> s;
		node[i] = {s - t, t};
	}

	std::sort(node.begin() + 1, node.end(), [](NODE n1, NODE n2) {
		return (n1.sta + n1.len) < (n2.sta + n2.len);
	});
	
	int lo = 0, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			int t = mid;
			bool tag = 0;
			for (int i = 1; i <= n; i++) {
				if (t > node[i].sta) {
					return 0;
				}
				t += node[i].len;
			}
			return 1;
		};

		if (check()) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}

	std::cout << ans << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}