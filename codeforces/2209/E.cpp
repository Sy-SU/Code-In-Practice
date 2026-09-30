#include <bits/stdc++.h>

using i64 = long long;

struct KMP {
	/*
	KMP kmp(str); // 使用模式串初始化
	auto kmp.findAll(text) -> std::vector<int>; // 在 text 中找 所有 p 出现的位置
	*/
	std::string p; // 模式串
	std::vector<int> pi; // 失配数组

	explicit KMP(const std::string &pat) {
		p = pat;
		pi.assign(p.size(), 0);
		for (int i = 1; i < (int)p.size(); i++) {
			int j = pi[i - 1];
			while (j > 0 && p[i] != p[j]) {
				j = pi[j - 1];
			}
			if (p[i] == p[j]) {
				j++;
			}
			pi[i] = j;
		}
	}

	std::vector<int> findAll(const std::string &text) {
		// 在 text 中找 所有 p 出现的位置
		std::vector<int> res;
		if (p.empty()) {
			return res;
		}

		int j = 0;
		for (int i = 0; i < (int)text.size(); i++) {
			while (j > 0 && text[i] != p[j]) {
				j = pi[j - 1];
			}
			if (text[i] == p[j]) {
				j++;
			}
			if (j == (int)p.size()) {
				res.push_back(i - (int)p.size() + 1);
				j = pi[j - 1]; 
			}
		}
		return res;
	}

	int findFirst(const std::string &text) {
		// 在 text 中找 p 第一次出现的位置
		if (p.empty()) {
			return -1;
		}

		int j = 0;
		for (int i = 0; i < (int)text.size(); i++) {
			while (j > 0 && text[i] != p[j]) {
				j = pi[j - 1];
			}
			if (text[i] == p[j]) {
				j++;
			}
			if (j == (int)p.size()) {
				return i - (int)p.size() + 1;
			}
		}
		return -1;
	}

	int findCount(const std::string &text) {
		// 在 text 中找 p 出现的次数
		if (p.empty()) {
			return 0;
		}

		int j = 0, res = 0;
		for (int i = 0; i < (int)text.size(); i++) {
			while (j > 0 && text[i] != p[j]) {
				j = pi[j - 1];
			}
			if (text[i] == p[j]) {
				j++;
			}
			if (j == (int)p.size()) {
				res++;
				j = pi[j - 1];
			}
		}
		return res;
	}
};

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string s;
	std::cin >> s;

	while (q--) {
		int l, r;
		std::cin >> l >> r;

		l--, r--;

		std::string str = s.substr(l, r - l + 1);
		
		int sz = str.size();
		
		KMP kmp(str);
		std::vector<int> dp(sz + 1), b(sz + 1);
		for (int i = 0; i < sz; i++) {
			if (kmp.pi[i] == 0) {
				b[i] = 0;
			} else if (kmp.pi[kmp.pi[i] - 1] == 0) {
				b[i] = kmp.pi[i];
			} else {
				b[i] = b[kmp.pi[i] - 1];
			}
		}

		i64 ans = 0;
		for (int i = 0; i < sz; i++) {
			dp[i + 1] = (b[i] ? dp[i + 1 - b[i]] + 1 : 1);
			ans += dp[i + 1];
		}
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