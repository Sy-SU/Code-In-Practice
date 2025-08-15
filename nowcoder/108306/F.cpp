#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<std::pair<i64, i64>> s(2), t(2);
	for (int i = 0; i < 2; i++) {
		std::cin >> s[i].first >> s[i].second;
	}
	for (int i = 0; i < 2; i++) {
		std::cin >> t[i].first >> t[i].second;
	}

	if (s[0].first == s[1].first) {
		std::swap(s[0].first, s[0].second);
		std::swap(s[1].first, s[1].second);
		std::swap(t[0].first, t[0].second);
		std::swap(t[1].first, t[1].second);
	}

	// std::cerr << "start : (" << s[0].first << ", " << s[0].second << ") (" << s[1].first << ", " << s[1].second << ")\n";
	// std::cerr << "end : (" << t[0].first << ", " << t[0].second << ") (" << t[1].first << ", " << t[1].second << ")\n"; 

	s[1].first -= s[0].first, s[1].second -= s[0].second;
	t[0].first -= s[0].first, t[0].second -= s[0].second;
	t[1].first -= s[0].first, t[1].second -= s[0].second;
	s[0].first = s[0].second = 0;

	t[0].second = std::abs(t[0].second), t[1].second = std::abs(t[1].second);
	// std::cerr << "start : (" << s[0].first << ", " << s[0].second << ") (" << s[1].first << ", " << s[1].second << ")\n";
	// std::cerr << "end : (" << t[0].first << ", " << t[0].second << ") (" << t[1].first << ", " << t[1].second << ")\n"; 

	if (std::min(t[0].first, t[1].first) < std::min(s[0].first, s[1].first)) {
		s[0].first = -s[0].first, s[1].first = -s[1].first;
		t[0].first = -t[0].first, t[1].first = -t[1].first;
	}
	// std::cerr << "start : (" << s[0].first << ", " << s[0].second << ") (" << s[1].first << ", " << s[1].second << ")\n";
	// std::cerr << "end : (" << t[0].first << ", " << t[0].second << ") (" << t[1].first << ", " << t[1].second << ")\n"; 

	if (s[1].first == -1) {
		t[1].first++, t[0].first++, s[1].first = 1;
	}

	if (t[0].first > t[1].first) {
		std::swap(t[0].first, t[1].first);
	}
	if (t[0].second > t[1].second) {
		std::swap(t[0].second, t[1].second);
	}
	// std::cerr << "start : (" << s[0].first << ", " << s[0].second << ") (" << s[1].first << ", " << s[1].second << ")\n";
	// std::cerr << "end : (" << t[0].first << ", " << t[0].second << ") (" << t[1].first << ", " << t[1].second << ")\n"; 

	// 现在保证起点一定是 (0, 0), (1, 0), 终点一定在第一象限

	// t 次操作后, (t / 2 + 1, (t + 1) / 2), ((t + 1) / 2, t / 2)
	// i64 mint = std::max(t[1].first * 2, t[].second * 2 - 1);
	// std::cerr << mint << " time: (" << (mint / 2 + 1) << ", " << (mint + 1) / 2 << ") ";
	// std::cerr << "(" << (mint + 1) / 2 << ", " << mint / 2 <<")\n";
	// std::cout << mint << '\n';

	i64 lo = 0, hi = 1e12;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 ti) -> bool {
			if ((ti + 1) / 2 >= t[0].first && ti / 2 >= t[0].second && (ti + 1) / 2 >= t[1].second && (ti / 2 + 1) >= t[1].first) {
				return 1;
			} else {
				return 0;
			}
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
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