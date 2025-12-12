#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string s;
	std::cin >> s;

	s = "X" + s + "I";

	std::vector<std::pair<int, int>> seq; // seq[i] : {len, type = 0 / 1}
	
	seq.push_back({0, 0});
	int cnt = 0, nowtype = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '?') {
			cnt++;
			if (s[i - 1] == 'I') {
				nowtype += 10;
			}
		} else {
			if (cnt != 0) {
				if (s[i] != 'I') {
					nowtype++;
				}
				// std::cerr << i << " " << cnt << " " << nowtype << " " << s[i + 1] << '\n';
				seq.push_back({cnt, nowtype});
			}
			cnt = 0, nowtype = 0;
		}
	}
	if (cnt != 0) {
		seq.push_back({cnt, nowtype});
	}

	// for (auto [len, tp] : seq) {
	// 	std::cerr << len << " " << tp << '\n';
	// }

	int val = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'I' && s[i + 1] == 'I') {
			val += 1;
		} else if (s[i] == 'I' && s[i + 1] != 'I') {
			if (s[i + 1] == '?') {
				val += 1;
			} else {
				val -= 1;
			}
		} else if (s[i] == 'V') {
			val += 5;
		} else if (s[i] == 'X') {
			val += 10;
		} else {
			res++;
		}
	}

	std::sort(seq.begin() + 1, seq.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
		return (p1.second == p2.second) ? (p1.first < p2.first) : (p1.second > p2.second);
	});

	// for (auto [len, tp] : seq) {
	// 	std::cerr << len << " " << tp << '\n';
	// }

	int ptr = 1; // -> seq

	std::vector<int> ansc(n + 1);

	int sta = -1;

	for (int ci = 1; ci <= res; ci++) {
		if (ptr >= (int)seq.size() || seq[ptr].second == 0) {
			sta = ci;
			break;
		} else {
			if (seq[ptr].second == 11 && seq[ptr].first % 2 == 0) {
				seq[ptr].second = 0, seq[ptr].first -= 2;
				ansc[ci] = ansc[ci - 1] - 1;
				ci++;
				ansc[ci] = ansc[ci - 1] - 1;
				ptr++;
			} else {
				seq[ptr].second--, seq[ptr].first--;
				ansc[ci] = ansc[ci - 1] - 1;
				ptr++;
			}
			
		}
	}

	ptr = 1;
	// std::cerr << "======" << '\n';
	// for (auto [len, tp] : seq) {
	// 	std::cerr << len << " " << tp << '\n';
	// }

	// std::cerr << "res = " << res << '\n';
	std::cerr << "val = " << val << '\n';

	int cnt2 = 0, cnt3 = 0;
	for (int ptr = 1; ptr < (int)seq.size(); ptr++) {
		cnt2 += seq[ptr].first / 2;
		cnt3 += (seq[ptr].first % 2 == 1);
	}

	if (sta != -1) {
		for (int ci = sta; ci <= sta + cnt2 - 1; ci++) {
			ansc[ci] = ansc[ci - 1] - 1;
		}

		for (int ci = sta + cnt2; ci <= sta + cnt2 + cnt3 - 1; ci++) {
			ansc[ci] = ansc[ci - 1] + 1;
		}

		for (int ci = sta + cnt2 + cnt3; ci <= res; ci++) {
			ansc[ci] = ansc[ci - 1] + 3;
		}
	}		

	for (int i = 1; i <= n; i++) {
		if (s[i] == 'I' && s[i + 1] == '?') {
			ansc[0] -= 2;
		}
	}

	for (int ci = res + 1; ci <= n; ci++) {
		ansc[ci] = ansc[res];
	}


	for (int ci = 0; ci <= n; ci++) {
		std::cerr << "ci = " << ci << " ans = " << ansc[ci] << '\n';
	}

	while (q--) {
		int cx, cv, ci;
		std::cin >> cx >> cv >> ci;

		int ans = ansc[ci] + val, tres = std::max(0, res - ci);

		int addv = std::min(tres, cv);
		ans += 5 * addv;
		tres -= addv, cv -= addv;

		int addx = std::min(tres, cx);
		ans += 10 * addx;
		tres -= addx, cv -= addx;

		std::cout << ans << '\n';
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