#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> org = a;

	i64 max = *std::max_element(a.begin() + 1, a.end());
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	if (max > sum - max || sum % 2) {
		std::cout << -1 << '\n';
		return;
	}

	std::vector<std::vector<i64>> op;
	std::vector<std::map<int, int>> tag;

	for (int __ = 1; __ <= 1; __++) {
		int l = 1, r = n;

		std::vector<i64> pre(n + 2), suf(n + 2);
		pre[l - 1] = 0, suf[r + 1] = 0;
		for (int i = l; i <= r; i++) {
			pre[i] = pre[i - 1] + a[i];
		}
		for (int i = r; i >= l; i--) {
			suf[i] = suf[i + 1] + a[i];
		}

		auto check = [&]() -> int {
			for (int i = l; i + 1 <= r; i++) {
				if (pre[i] == suf[i + 1]) {
					return i;
				}
			}
			return -1;
		};

		if (check() != -1) {
			std::cout << 1 << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << a[i] << " \n"[i == n];
			}
			return;
		}

		int pos = -1;
		for (int i = l + 1; i + 1 <= r; i++) {
			if (pre[i - 1] + a[i] > suf[i + 1] && pre[i - 1] < suf[i + 1] + a[i]) {
				pos = i;
				break;
			}
		}

		assert(pos != -1);

		std::vector<i64> tmp(n + 1);
		tmp[pos] = a[pos];

		i64 lneed = 0, rneed = 0;
		if (pre[pos - 1] > suf[pos + 1]) {
			lneed = pre[pos - 1] - suf[pos + 1];
		} else {
			rneed = suf[pos + 1] - pre[pos - 1];
		}

		lneed += (a[pos] - std::abs(pre[pos - 1] - suf[pos + 1])) / 2;
		rneed += (a[pos] - std::abs(pre[pos - 1] - suf[pos + 1])) / 2;

		int ptrl = pos - 1, ptrr = pos + 1;
		i64 suml = 0, sumr = 0;

		// std::cerr << lneed << " " << rneed << " " << pos << '\n';

		while (suml < lneed) {
			tmp[ptrl] = std::min(lneed - suml, a[ptrl]);
			suml += std::min(lneed - suml, a[ptrl]);
			assert(ptrl >= l);
			ptrl--;
		}

		while (sumr < rneed) {
			tmp[ptrr] = std::min(rneed - sumr, a[ptrr]);
			sumr += std::min(rneed - sumr, a[ptrr]);
			assert(ptrr <= r);
			ptrr++;
		}

		std::vector<i64> del(n + 1);
		for (int i = 1; i <= n; i++) {
			del[i] = a[i] - tmp[i];
		}
		// for (int i = 1; i <= n; i++) std::cerr <<del[i] << " \n"[i == n];

		std::map<int, int> vis;
		i64 pd = del[1], sd = 0;
		for (int i = 2; i <= n; i++) {
			sd += del[i];
		} 
		for (int i = 1; i < n; i++) {
			if (pd == sd) {
				vis[i] = 1;
			}
			// std::cerr << "pd += " << del[i + 1] << '\n';
			pd += del[i + 1], sd -= del[i + 1];
		}
		tag.push_back(vis);

		assert(!vis.empty());

		op.push_back(del);

		a = tmp;
	}

	// std::cerr << "[DEBUG]";
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	// std::cout << op.size() << '\n';
	// for (const auto &vec : op) {
	// 	for (int i = 1; i <= n; i++) {
	// 		std::cout << vec[i] << " \n"[i == n];
	// 	}
	// }

	max = *std::max_element(a.begin() + 1, a.end());
	int maxpos = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == max) {
			maxpos = i;
			break;
		}
	}

	// for (int i = 1; i <= n; i++) std::cerr << a[i] << " \n"[i == n];

	std::vector<i64> pre(n + 2), suf(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	std::vector<i64> tmppre(n + 2), tmpsuf(n + 2);
	for (int i = 1; i <= maxpos - 1; i++) {
		tmppre[i] = a[i];
	}
	tmppre[maxpos] = pre[maxpos - 1];
	for (int i = maxpos + 1; i <= n; i++) {
		tmpsuf[i] = a[i];
	}
	tmpsuf[maxpos] = suf[maxpos + 1];

	if (tmppre[maxpos]) {
		op.push_back(tmppre);
		std::map<int, int> vis;
		vis[maxpos - 1] = 1;
		tag.push_back(vis);
	}
	if (tmpsuf[maxpos]) {
		op.push_back(tmpsuf);
		std::map<int, int> vis;
		vis[maxpos] = 1;
		tag.push_back(vis);
	}

	// std::cerr << op.size() << '\n';
	// for (const auto &vec : op) {
	// 	for (int i = 1; i <= n; i++) {
	// 		org[i] -= vec[i];
	// 		std::cerr << vec[i] << " \n"[i == n];
	// 	}
	// }


	int opsz = op.size();
	for (int i = 1; i < opsz; i++) {
		int x = -1;
		for (auto [_, __] : tag[i]) {
			x = _;
		}

		if (tag[0][x] == 1) {
			// std::cerr << "merge" << 0 << " " << i << '\n';
			for (int j = 1; j <= n; j++) {
				op[0][j] += op[i][j];
			}
			op.erase(op.begin() + i);
			break;
		}
	}

	std::cout << op.size() << '\n';
	for (const auto &vec : op) {
		for (int i = 1; i <= n; i++) {
			org[i] -= vec[i];
			std::cout << vec[i] << " \n"[i == n];
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	assert(org[i] == 0);
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