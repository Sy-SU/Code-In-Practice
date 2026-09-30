#include <bits/stdc++.h>

using i64 = long long;

std::vector<std::vector<int>> ok(1000000 + 10);

auto D = [](i64 x) -> i64 {
	i64 sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
};

void solve() {
	std::string s;
	std::cin >> s;

	auto gen = [&](i64 x) -> std::vector<i64> {
		std::vector<i64> res;
		for (i64 num = 10; num <= 54; num++) {
			i64 _n = num, sum = 0;
			while (_n) {
				sum += _n % 10;
				_n /= 10;
			}
			if (sum == x) {
				res.push_back(num);
			}
		}
		return res;
	};

	int cnt[10];
	for (int i = 0; i <= 9; i++) {
		cnt[i] = 0;
	}
	for (auto ch : s) {
		cnt[ch - '0']++;
	}

	auto its = [&](i64 num) -> std::string {
		std::string res;
		while (num) {
			res.push_back('0' + num % 10);
			num /= 10;
		}

		std::reverse(res.begin(), res.end());
		return res;
	};



	auto S = [&](i64 x) -> std::string {
		std::string res;

		res += its(x);
		while (x != D(x)) {
			x = D(x);
			res += its(x);
		}

		return res;
	};

	std::string ans;


	auto dfs = [&](auto &&self, int now) -> void {
		if (ans.size() != 0) {
			return;
		}
		// std::cerr << now << '\n';

		// 如果是最后一层 check
		{
			auto res = S(now);
			int nu[10];
			for (int i = 0; i <= 9; i++) {
				nu[i] = 0;
			}
			for (auto ch : res) {
				nu[ch - '0']++;
			}

			bool isok = 1;
			for (int i = 0; i <= 9; i++) {
				if (nu[i] != cnt[i]) {
					isok = 0;
					break;
				}
			}

			if (isok) {
				ans = res;
				return;
			}
		}

		// 如果是倒数第二层 看数字和
		{
			auto res = S(now);
			int nu[10];
			for (int i = 0; i <= 9; i++) {
				nu[i] = 0;
			}
			for (auto ch : res) {
				nu[ch - '0']++;
			}

			int cpcnt[10];
			for (int i = 0; i <= 9; i++) {
				cpcnt[i] = cnt[i] - nu[i];
			}

			i64 sum = 0;
			bool isok = 1;
			for (int i = 0; i <= 9; i++) {
				if (cpcnt[i] < 0) {
					isok = 0;
				} else {
					sum += i * 1ll * cpcnt[i];
				}
			}

			std::string pre;
			if (sum != now) {
				isok = 0;
			} else {
				for (int i = 9; i >= 0; i--) {
					for (int j = 1; j <= cpcnt[i]; j++) {
						pre += '0' + i;
					}
				}

				if (pre.empty() || pre[0] == '0') {
					isok = 0;
				}
			}

			if (isok) {
				ans = pre + res;
				return;
			}
		}

		// 如果是倒数第三层
		{
			for (auto nxt : ok[now]) {
				if (D(nxt) != now) {
					continue;
				}
				auto res = S(nxt);

				int nu[10];
				for (int i = 0; i <= 9; i++) {
					nu[i] = 0;
				}
				for (auto ch : res) {
					nu[ch - '0']++;
				}

				int cpcnt[10];
				for (int i = 0; i <= 9; i++) {
					cpcnt[i] = cnt[i] - nu[i];
				}
				i64 sum = 0;
				bool isok = 1;
				for (int i = 0; i <= 9; i++) {
					if (cpcnt[i] < 0) {
						isok = 0;
					} else {
						sum += i * 1ll * cpcnt[i];
					}
				}
				std::string pre;
				if (sum != nxt) {
					isok = 0;
				} else {
					for (int i = 9; i >= 0; i--) {
						for (int j = 1; j <= cpcnt[i]; j++) {
							pre.push_back('0' + i);
						}
					}

					if (pre.empty() || pre[0] == '0') {
						isok = 0;
					}
				}
				if (isok) {
					ans = pre + res;
					return;
				}
			}
		}

		auto can = gen(now); 
		for (auto to : can) {
			// std::cerr << now << "->" << to << '\n';
			self(self, to);
		}

		// std::cerr << "end" << '\n';
	};

	for (int i = 1; i <= 9; i++) {
		// std::cerr << "nnn" << cnt[0] << '\n';
		dfs(dfs, i);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	for (int i = 1; i <= 900000; i++) {
		ok[D(i)].push_back(i);
	}

	while (t--) {
		solve();
	}

	return 0;
}