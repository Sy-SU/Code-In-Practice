#include <bits/stdc++.h>

using i64 = long long;

struct Seg {
	i64 l, r;
	int ind;

	bool operator > (const Seg &s) const {
		return (l == s.l ? r > s.r : l > s.l);
	}
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<Seg> s(n + 1);
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		int l, r;
		std::cin >> l >> r;

		s[i] = {l, r, i};
		ans += r - l;
	}

	std::sort(s.begin() + 1, s.end(), [](Seg s1, Seg s2) {
		return (s1.r + s1.l) < (s2.r + s2.l);
	});

	if (n % 2) {
		for (int i = 1; i <= n; i++) {
			ans -= s[i].l;
		}

		i64 suf = 0;
		for (int i = n - n / 2 + 1; i <= n; i++) {
			suf += s[i].l + s[i].r;
		}

		i64 add = 0;
		for (int i = 1; i <= (n + 1) / 2; i++) {
			add = std::max(add, suf + s[i].l);
		}
		for (int i = (n + 1) / 2 + 1; i <= n; i++) {
			add = std::max(add, suf - s[i].r + s[(n + 1) / 2].l + s[(n + 1) / 2].r);
		}

		ans += add;
	} else {
		for (int i = 1; i <= n / 2; i++) {
			ans -= s[i].l;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			ans += s[i].r;
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