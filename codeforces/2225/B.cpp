#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.size();
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 && s[i] == s[0]) {
			l = i;
			break;
		}
		if (i % 2 == 0 && s[i] != s[0]) {
			l = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (i % 2 && s[i] == s[0]) {
			r = i;
			break;
		}
		if (i % 2 == 0 && s[i] != s[0]) {
			r = i;
			break;
		}
	}

	// l ~ r
	// std::cerr << l << " " << r << '\n';

	auto t = s;
	for (int i = l; i <= r; i++) {
		t[i] = s[l + r - i];
	}

	bool isok = 0;

	bool ck1 = 1;
	for (int i = 1; i < n; i++) {
		if (t[i] == t[i - 1]) {
			ck1 = 0;
		}
	}

	isok |= ck1;

	for (int i = l; i <= r; i++) {
		t[i] = (t[i] == 'a' ? 'b' : 'a');
	}

	bool ck2 = 1;
	for (int i = 1; i < n; i++) {
		if (t[i] == t[i - 1]) {
			ck2 = 0;
		}
	}

	isok |= ck2;

	std::cout << (isok ? "YES" : "NO") << '\n';
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