#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<std::pair<int, char>> col(3);
	int r, g, b;
	std::cin >> r >> g >> b;
	col[0] = {r, 'R'}, col[1] = {g, 'G'}, col[2] = {b, 'B'};

	std::sort(col.begin(), col.end());

	int cl0 = col[0].first, cl1 = col[1].first, cl2 = col[2].first;

	if (col[2].first >= col[1].first + col[0].first + 1) {
		col[2].first = col[1].first + col[0].first + 1;
		cl2 = cl1 + cl0 + 1;

		std::string s;
		s.push_back(col[2].second);
		for (int i = 1; i <= col[2].first - 1; i++) {
			if (i <= col[1].first) {
				s.push_back(col[1].second);
			} else {
				s.push_back(col[0].second);
			}
			s.push_back(col[2].second);
		}
		std::cout << s << '\n';

		assert(s.size() == cl0 + cl1 + cl2);
		for (int i = 0; i < (int)s.size() - 3; i++) {
			assert(s[i] != s[i + 3]);
		}
		for (int i = 0; i < (int)s.size() - 1; i++) {
			assert(s[i] != s[i + 1]);
		}
		return;
	}

	std::string s;

	int c0 = col[0].first;
	if (c0 > 0) {
		s.push_back({col[1].second});
		s.push_back({col[2].second});
		s.push_back({col[0].second});
		col[1].first--, col[2].first--, col[0].first--;
		for (int i = 1; i <= c0; i++) {
			if (col[0].first == 0 || col[0].first + col[1].first + 1 == col[2].first) {
				break;
			}
			s.push_back(s[3 * i - 2]);
			s.push_back(s[3 * i - 1]);
			s.push_back(s[3 * i - 3]);
			col[1].first--, col[2].first--, col[0].first--;
		}
	}

	// std::cout << col[0].first << " " << col[1].first << " " << col[2].first << '\n';
	int cp0 = col[0].first, cp1 = col[1].first;
	std::reverse(s.begin(), s.end());
	if (col[2].first > 0) {
		s.push_back(col[2].second);
		col[2].first--;
		for (int i = 1; i <= cp0 + cp1; i++) {
			if (i <= cp1) {
				s.push_back(col[1].second);
				col[1].first--;
			} else {
				s.push_back(col[0].second);
				col[0].first--;
			}
			if (col[2].first > 0) {
				s.push_back(col[2].second);
				col[2].first--;
			}
		}	
	}

	std::cout << s << '\n';

	assert(s.size() == cl0 + cl1 + cl2);
	for (int i = 0; i < (int)s.size() - 3; i++) {
		assert(s[i] != s[i + 3]);
	}
	for (int i = 0; i < (int)s.size() - 1; i++) {
		assert(s[i] != s[i + 1]);
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