#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s, t;
	std::cin >> s >> t;

	auto work = [&](std::string str) -> std::vector<std::pair<int, int>> {
		std::vector<std::pair<int, int>> op, seg;

		str = " " + str;

		auto modify = [&](int l, int r) -> void {
			for (int i = l; i <= r; i++) {
				str[i] = '1' - str[i] + '0';
			}
		};

		int lst = 1;
		for (int i = 2; i <= n; i++) {
			if (str[i] != str[i - 1]) {
				seg.push_back({lst, i - 1});
				lst = i;
			}
		}
		seg.push_back({lst, n});

		// for (auto [l, r] : seg) {
		// 	std::cerr << l << " " << r << '\n';
		// }
		// std::cerr << "////" << '\n';

		bool isf = 0;
		for (int i = 0; i < (int)seg.size(); i++) {
			auto [l, r] = seg[i];
			if (l != r) {
				isf = 1;
				op.push_back({l, r}), modify(l, r);
				for (int j = i - 1; j >= 1; j--) {
					op.push_back({seg[j].first, r}), modify(seg[j].first, r);
				}
				if (op.size() % 2 == 0) {
					op.push_back({1, r}), modify(1, r);
				}
				for (int j = i + 1; j < (int)seg.size(); j++) {
					op.push_back({1, seg[j].second}), modify(1, seg[j].second);
				}
				if (str[n] == '1') {
					op.push_back({1, n}), modify(1, n);
				}
				break;
			}
		}
		if (isf == 0) {
			op.push_back({2, 4}), modify(2, 4);
			lst = 1;
			seg.clear();
			for (int i = 2; i <= n; i++) {
				if (str[i] != str[i - 1]) {
					seg.push_back({lst, i - 1});
					lst = i;
				}
			}
			seg.push_back({lst, n});
			
			for (int i = 0; i < (int)seg.size(); i++) {
				auto [l, r] = seg[i];
				if (l != r) {
					isf = 1;
					op.push_back({l, r}), modify(l, r);
					for (int j = i - 1; j >= 1; j--) {
						op.push_back({seg[j].first, r}), modify(seg[j].first, r);
					}
					if (op.size() % 2 == 1) {
						op.push_back({1, r}), modify(1, r);
					}
					for (int j = i + 1; j < (int)seg.size(); j++) {
						op.push_back({1, seg[j].second}), modify(1, seg[j].second);
					}
					if (str[n] == '1') {
						op.push_back({1, n}), modify(1, n);
					}
					break;
				}
			}
		}
 
		return op;
	};

	auto ops = work(s);
	auto opt = work(t);

	std::reverse(opt.begin(), opt.end());

	auto ans = ops;
	for (auto [l, r] : opt) {
		ans.push_back({l, r});
	}

	std::vector<std::pair<int, int>> cans;
	for (auto o : ans) {
		if (!cans.empty() && o == cans.back()) {
			cans.pop_back();
			// cans.push_back(o);
		} else {
			cans.push_back(o);
		}
	}

	std::cout << cans.size() << '\n';
	for (auto [l, r] : cans) {
		std::cout << l << " " << r << '\n';
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