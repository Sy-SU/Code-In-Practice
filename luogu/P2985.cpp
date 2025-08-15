#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, d;
	std::cin >> n >> d;

	std::vector<i64> h(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}

	i64 lo = 1, hi = 1e12;
	i64 ans = 0;
	std::vector<int> output(n + 1, 0);
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2, tmp = 0;
		int ind = 0;
		std::vector<int> tmpOutput(n + 1, 0);

		auto check = [&]() -> bool {
			for (int i = 1; i <= d; i++) {
				tmp /= 2;
				while (tmp < mid) {
					if (ind == n) {
						return 0;
					}
					tmp += h[++ind];
					tmpOutput[ind] = i;
				}
			}

			for (int i = ind + 1; i <= n; i++) {
				tmpOutput[i] = d;
			}
			return 1;
		};

		if (check()) {
			lo = mid + 1;
			ans = mid, output = tmpOutput;
		} else {
			hi = mid - 1;
		}
	}

	std::cout << ans << '\n';
	for (int i = 1; i <= (int)output.size() - 1; i++) {
		std::cout << output[i] << '\n';
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}