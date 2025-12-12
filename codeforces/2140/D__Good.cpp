#include <bits/stdc++.h>

using i64 = long long;

struct Seg {
	i64 l, r;
	int ind;
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<Seg> s(n + 1);
	for (int i = 1; i <= n; i++) {
		int l, r;
		std::cin >> l >> r;

		s[i] = {l, r, i};
	}

	std::map<int, bool> vis;

	auto a = s, b = s;
	std::sort(a.begin() + 1, a.end(), [](Seg s1, Seg s2) {
		return s1.l < s2.l;
	});

	std::sort(b.begin() + 1, b.end(), [](Seg s1, Seg s2) {
		return s1.r > s2.r;
	});

	int ptr2 = 1;
	i64 ans = 0;
	for (int ptr1 = 1; ptr1 <= n; ptr1++) {
		if (vis[a[ptr1].ind]) {
			continue;
		}
		while (ptr2 <= n && (vis[b[ptr2].ind] || (a[ptr1].ind == b[ptr2].ind))) {
			ptr2++;
		}

		if (ptr2 > n) {
			break;
		}

		// std::cerr << "chs" << a[ptr1].l << " " << a[ptr1].r << " and " << b[ptr2].l << " " << b[ptr2].r << '\n';

		vis[a[ptr1].ind] = 1, vis[b[ptr2].ind] = 1;
		ans += a[ptr1].r - a[ptr1].l;
		ans += b[ptr2].r - b[ptr2].l;
		ans += std::max({std::abs(a[ptr1].r - b[ptr2].r), std::abs(a[ptr1].r - b[ptr2].l), std::abs(a[ptr1].l - b[ptr2].r), std::abs(a[ptr1].l - b[ptr2].l)});
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[s[i].ind]) {
			ans += s[i].r - s[i].l;
			cnt++;
			assert(cnt <= 1);
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