#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	auto check1 = [&](std::vector<int> arr) -> int {
		int sz = arr.size();
		std::priority_queue<int> pq;
		bool isok = 0;
		for (int i = 0; i < sz; i++) {
			pq.push(arr[i]);
			if (pq.size() > i / 2 + 1) {
				pq.pop();
			}
			if (isok && arr[i] <= k) {
				return i - 1;
			}
			if (isok && pq.top() > k) {
				return i - 1;
			}
			if (isok && i == n - 2) {
				return i - 1;
			}
			if (pq.top() <= k) {
				isok = 1;
			}
		}
		return -1;
	};

	auto check2 = [&](std::vector<int> arr) -> int {
		int sz = arr.size();
		std::priority_queue<int> pq;
		for (int i = 0; i < sz; i++) {
			pq.push(arr[i]);
			if (pq.size() > i / 2 + 1) {
				pq.pop();
			}
			if (pq.top() <= k) {
				return i;
			}
		}
		return -1;
	};	

	// case 1 : l, mid
	int r = check1(a);
	if (r != -1) {
		// 0 ~ r
		std::vector<int> b, c;
		for (int i = r + 1; i < n; i++) {
			b.push_back(a[i]);
		}
		for (int i = n - 1; i >= r + 1; i--) {
			c.push_back(a[i]);
		}
		int szb = b.size();
		if (check2(b) != -1 && check2(b) != szb - 1) {
			std::cout << "YES" << '\n';
			return;
		}
		if (check2(c) != -1 && check2(c) != szb - 1) {
			std::cout << "YES" << '\n';
			return;
		}
	}
	
	std::vector<int> ra;
	for (int i = n - 1; i >= 0; i--) {
		ra.push_back(a[i]);
	}

	int rr = check1(ra);
	if (rr != -1) {
		std::vector<int> d;
		for (int i = rr + 1; i < n; i++) {
			d.push_back(ra[i]);
		}
		int szd = d.size();
		if (check2(d) != -1 && check2(d) != szd - 1) {
			std::cout << "YES" << '\n';
			return;
		}
	}
	std::cout << "NO" << '\n';
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