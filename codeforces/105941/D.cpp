#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x;
	std::cin >> x;

	int sq = sqrtl(x);
	if (sq * sq != x) {
		std::cout << "NO" << '\n';
		return;
	}

	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	int sqs = sqrtl(sum);
	if (sqs * sqs != sum) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}