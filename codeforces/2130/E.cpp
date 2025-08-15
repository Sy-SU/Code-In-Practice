#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int lo = 1, hi = n;

	while (lo + 1 <= hi) {
		int mid = (lo + hi) / 2;
		std::cout << "? " << 2 * (mid - lo + 1) << " ";
		for (int i = lo; i <= mid; i++) {
			std::cout << i << " ";
		}
		for (int i = lo; i <= mid; i++) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		int res;
		std::cin >> res;
		if (res == 0) {
			lo = mid;
		} else {
			hi = mid;
		}

		if (lo == hi - 1) {
			break;
		}
	}
	int indl = -1, indr = -1;
	std::cout << "? 4 " << lo << " " << hi << " " << lo << " " << hi << std::endl;
	int res;
	std::cin >> res;

	if (res == 3) {
		indl = lo, indr = hi;
	} else if (res == 1) {
		indl = hi, indr = lo;
	} else {
		assert(0);
	}

	std::vector<char> s(n + 1);
	s[indl] = '(', s[indr] = ')';

	std::vector<int> op;
	for (int i = 1; i <= n; i++) {
		if (i == indl || i == indr) {
			continue;
		}
		op.push_back(i);
	}

	for (int i = 0; i < (int)op.size(); i += 2) {
		if (i == (int)op.size() - 1) {
			std::cout << "? 2 " << indl << " " << op[i] << std::endl;
			int res;
			std::cin >> res;
			if (res == 1) {
				s[op[i]] = ')';
			} else {
				s[op[i]] = '(';
			}
		} else {
			int id1 = op[i], id2 = op[i + 1];
			std::cout<< "? 6 " << indl << " " << indr << " " << id1 << " " << indr << " " << indl << " " << id2 << std::endl;
			int res;
			std::cin >> res;
			if (res == 3) {
				s[id1] = '(', s[id2] = '(';
			} else if (res == 6) {
				s[id1] = '(', s[id2] = ')';
			} else if (res == 1) {
				s[id1] = ')', s[id2] = '(';
			} else if (res == 2) {
				s[id1] = ')', s[id2] = ')';
			} else {
				assert(0);
			}	
		}
 	}

 	std::cout << "! ";
 	for (int i = 1; i <= n; i++) {
 		std::cout << s[i];
 	}
 	std::cout << std::endl;


}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}