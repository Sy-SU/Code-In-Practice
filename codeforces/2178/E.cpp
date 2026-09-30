#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);

	auto query = [&](int l, int r) -> i64 {
		if (l > r) {
			return 0;
		}
		std::cout << "? " << l << " " << r << std::endl;

		i64 res;
		std::cin >> res;
		return res;
	};

	int left = 1, right = n, ans = -1;
	while (1) {
		if (left == right) {
		    auto ans = query(left, left);
			std::cout << "! " << ans << std::endl;
			return;
		}
		int lo = left, hi = right, next = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			auto check = [&](int m) -> bool {
				auto res1 = query(left, m);
				auto res2 = query(m + 1, right);

				return res1 <= res2;
			};

			std::cerr << "check " << lo << " " << hi << " " << mid << "\n";

			if (check(mid)) {
				lo = mid + 1;
				next = mid;
			} else {
				hi = mid - 1;
			}
		}
		std::cerr << left << " " << next << " " << right << '\n';
		if (next - left + 1 <= right - (next + 1) + 1) {
			right = next;
		} else {
			left = next + 1;
		}
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