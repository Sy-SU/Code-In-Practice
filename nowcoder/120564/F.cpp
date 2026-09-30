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
	std::cin >> b >> a;

	bool sp = 0;
	if (a > b) {
		std::swap(a, b);
		sp = 1;
	}

	int n = a + b;

	std::string s;

	int base = b / (a + 1);
	int res = b % (a + 1);
	// a + 1 - res * base, res * base + 1
	for (int i = 1; i <= a + 1 - res; i++) {
		s += "1";
		for (int j = 1; j <= base; j++) {
			s += "0";
		}
	}
	for (int i = 1; i <= res; i++) {
		s += "1";
		for (int j = 1; j <= base + 1; j++) {
			s += "0";
		}
	}

	std::string t;

	for (int i = 1; i <= n; i++) {
		if (sp) {
			t += '0' + '1' - s[i];
		} else {
			t += s[i];
		}
	}

	std::cout << t << '\n';
	// std::cerr << calc(t) << '\n';
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