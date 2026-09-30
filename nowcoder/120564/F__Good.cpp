#include <bits/stdc++.h>

using i64 = long long;

int calc(std::string s) {
	int n = s.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int cnt0 = 0, cnt1 = 0;
			for (int x = i; x <= j; x++) {
				if (s[x] == '0') cnt0++;
				else cnt1++;
			}

			if (cnt0 == 0) sum += 0;
			else if (cnt1 == 0) sum += 1;
			else sum += 2;
		}
	}
	return sum;
}

void solve() {
	int a, b;
	std::cin >> a >> b;

	int n = a + b;
	int best = 0;
	for (int _ = 0; _ < (1 << n); _++) {
		int nows = _;
		std::string s;
		int cnta = 0;
		for (int i = 0; i < n; i++) {
			if (nows % 2) {
				s += "1";
				cnta++;
			} else {
				s += "0";
			}
			nows /= 2;
		}

		// std::cerr << _ << " " << s << '\n';

		if (cnta != a) {
			continue;
		}

		int sum = calc(s);
		best = std::max(best, sum);
	}

	std::cerr << best << '\n';

	// for (int _ = 0; _ < (1 << n); _++) {
	// 	int nows = _;
	// 	std::string s;
	// 	int cnta = 0;
	// 	for (int i = 0; i < n; i++) {
	// 		if (nows % 2) {
	// 			s += "1";
	// 			cnta++;
	// 		} else {
	// 			s += "0";
	// 		}
	// 		nows /= 2;
	// 	}

	// 	if (cnta != a) {
	// 		continue;
	// 	}

	// 	int sum = calc(s);
	// 	if (sum == best) {
	// 		std::cerr << s << '\n';
	// 	}
	// }
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