#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::string str;
	std::cin >> str;

	std::map<std::string, int> cnt;

	int precntbc = 0, precntcb = 0;
	while (q--) {
		std::string x, y;
		std::cin >> x >> y;

		if (x == y) {
			continue;
		}

		std::string op = x + y;

		cnt[op]++;
		if (op == "ca") {
			precntbc = cnt["bc"];
		}
		if (op == "ba") {
			precntcb = cnt["cb"];
		}
	}

	for (int i = 0; i < n; i++) {
		if (str[i] == 'a') {
			continue;
		}
		if (str[i] == 'c') {
			if (cnt["ca"]) {
				cnt["ca"]--;
				str[i] = 'a';
			} else if (cnt["cb"]) {
				if (cnt["ba"]) {
					if (cnt["cb"] < precntcb) {
						cnt["cb"]--;
						str[i] = 'b';
					} else {
						cnt["cb"]--, cnt["ba"]--;
						str[i] = 'a';
						precntcb--;
					}
				} else {
					cnt["cb"]--;
					str[i] = 'b';
				}

			}
		} else if (str[i] == 'b') {
			if (cnt["ba"]) {
				cnt["ba"]--;
				str[i] = 'a';
			} else if (cnt["bc"] && cnt["ca"]) {
				if (cnt["bc"] < precntbc) {
					continue;
				}
				cnt["bc"]--, cnt["ca"]--;
				str[i] = 'a';
				precntbc--;
			}
		}
	}

	// for (const auto &[op, cn] : cnt) {
	// 	std::cerr << op << " " << cn << '\n';
	// }

	std::cout << str << '\n';

	// aaaaaaaaaaaaaaabbbabcbabbbbabc
	// aaaaaaaaaaaaaaabbbabcbabbbbabc
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