#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x, s;
	std::cin >> n >> x >> s;

	std::string str;
	std::cin >> str;

	str = " " + str;

	std::vector<i64> cnt(x + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (str[i] == 'I') {
			int lo = 1, hi = x;
			int fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (cnt[mid] == -1) {
					hi = mid - 1;
					fd = mid;
				} else {
					lo = mid + 1;
				}
			}

			if (fd != -1) {
				cnt[fd] = 1;
			}
		} else if (str[i] == 'E') {
			int lo = 1, hi = x;
			int fd = 0;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (cnt[mid] == s) {
					lo = mid + 1;
					fd = mid;
				} else {
					hi = mid - 1;
				}
			}
			fd++;

			if (fd <= x && cnt[fd] != -1) {
				cnt[fd]++;
			}
		} else {
			int lo = 1, hi = x;
			int fd = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (cnt[mid] == -1) {
					hi = mid - 1;
					fd = mid;
				} else {
					lo = mid + 1;
				}
			}

			if (fd != -1) {
				cnt[fd] = 1;
			} else {
				lo = 1, hi = x;
				fd = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if (cnt[mid] == 0) {
						hi = mid - 1;
						fd = mid;
					} else {
						lo = mid + 1;
					}
				}

				if (fd == -1) {
					lo = 1, hi = x;
					fd = -1;
					while (lo <= hi) {
					int mid = (lo + hi) / 2;
						if (cnt[mid] == s) {
							lo = mid + 1;
							fd = mid;
						} else {
							hi = mid - 1;
						}
					}
					fd++;

					if (fd <= x && cnt[fd] != -1) {
						cnt[fd]++;
					}
				} else {
					cnt[fd]++;
				}
			}
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= x; i++) {
		if (cnt[i] == -1) {
			break;
		}
		ans += cnt[i];
	}
	std::cout << ans << '\n';
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