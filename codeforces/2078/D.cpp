#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<i64>> add(n + 2, std::vector<i64>(2)), mul(n + 2, std::vector<i64>(2));
	
	std::vector<std::vector<std::pair<char, i64>>> vec(2);
	for (int i = 1; i <= n; i++) {
		char op1, op2;
		i64 num1, num2;
		std::cin >> op1 >> num1 >> op2 >> num2;
		vec[0].push_back({op1, num1});
		vec[1].push_back({op2, num2});
	}

	add[n + 1][0] = add[n + 1][1] = 0, mul[n + 1][0] = mul[n + 1][1] = 1;
	for (int i = n; i >= 1; i--) {
		auto &[op1, num1] = vec[0][i - 1];
		auto &[op2, num2] = vec[1][i - 1];

		if (op1 == '+') {
			add[i][0] = add[i + 1][0] + num1;
			mul[i][0] = mul[i + 1][0];
		} else {
			add[i][0] = add[i + 1][0] * num1;
			mul[i][0] = mul[i + 1][0] * num1;
		}

		if (op2 == '+') {
			add[i][1] = add[i + 1][1] + num2;
			mul[i][1] = mul[i + 1][1];
		} else {
			add[i][1] = add[i + 1][1] * num2;
			mul[i][1] = mul[i + 1][1] * num2;
		}
	}

	std::vector<std::pair<i64, i64>> oklr;
	oklr.push_back({1, 1});
	for (int i = 1; i <= n; i++) {
		std::vector<std::pair<i64, i64>> tmp;
		for (const auto &[l, r] : oklr) {
			i64 bonus = 0;
			auto &[op1, num1] = vec[0][i - 1];
			auto &[op2, num2] = vec[1][i - 1];

			if (op1 == '+') {
				bonus += num1;
			} else {
				bonus += (num1 - 1) * l;
			}

			if (op2 == '+') {
				bonus += num2;
			} else {
				bonus += (num2 - 1) * r;
			}

			tmp.push_back({l + bonus, r}), tmp.push_back({l, r + bonus});
		}
		std::sort(tmp.begin(), tmp.end());
		oklr.clear();

		int sz = tmp.size();
		i64 maxv = 0;
		for (int ii = sz - 1; ii >= 0; ii--) {
			if (maxv >= tmp[ii].second) {
				continue;
			}
			maxv = tmp[ii].second;
			oklr.push_back(tmp[ii]);
		}
	}
	i64 ans = 0;
	for (const auto &[l, r] : oklr) {
		ans = std::max(ans, l + r);
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