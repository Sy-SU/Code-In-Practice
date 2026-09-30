#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	i64 ans = 0, sum = 0;
	std::priority_queue<i64, std::vector<i64>, std::greater<i64>> workq;
	std::priority_queue<i64> candi;

	int freew = 0;
	int lstwday = -1;

	std::vector<i64> op(n + 2, -1);
	for (int day = 1; day <= n; day++) {
		char o;
		std::cin >> o;

		if (o == 'F') {
			i64 x;
			std::cin >> x;

			op[day] = x;
		}
	}

	for (int day = 1; day <= n; day++) {
		i64 tmpsumf = 0;
		if (op[day] == -1) {
			if (candi.empty()) {
				freew++;
			} else {
				auto nc = candi.top();
				candi.pop();
				workq.push(nc);

				sum += nc;
				// std::cerr << "nc = " << nc << " " << workq.size() << '\n';
				// std::cerr << "sum = = " << sum << '\n';
				while (!candi.empty() && !workq.empty()) {
					auto tpcan = candi.top();
					auto tpworkq = workq.top();

					// std::cerr << tpcan << " " << tpworkq << '\n';

					if (tpcan <= tpworkq) {
						break;
					}

					candi.pop();
					workq.pop();

					sum += tpcan - tpworkq;
					workq.push(tpcan), candi.push(tpworkq);
				}
			}
			lstwday = day;
		} else {
			int l = day, r = day;
			while (op[r] != -1) {
				r++;
			}
			r--;

			// std::cerr << "l r : " << l << " " << r << " are F" << '\n';

			// freew 次

			std::priority_queue<i64, std::vector<i64>, std::greater<i64>> popworkq;
			for (int i = 1; i <= r - l + 1; i++) {
				if (!workq.empty()) {
					popworkq.push(workq.top());
					sum -= workq.top();
					workq.pop();
				}
			}

			// std::cerr << "done1" << '\n';

			for (int i = 1; i <= freew; i++) {
				popworkq.push(0);
			}

			freew = 0;

			// (r - lstwday + 1) * popwork.top()
			// (r - i + 1) * op[i]

			std::priority_queue<std::pair<i64, i64>> candif;
			for (int i = l; i <= r; i++) {
				candif.push({(r - i + 1) * op[i], op[i]});
			}

			// std::cerr << "done2" << '\n';
			while (!candif.empty() && !popworkq.empty()) {
				auto [bonus, f] = candif.top();
				auto popq = popworkq.top();

				if (bonus < popq * (r - lstwday + 1)) {
					break;
				}

				ans += bonus - popq;
				// sum -= popq;
				workq.push(f);
				if (popq) {
					candi.push(popq);
				}
				sum += f;
				tmpsumf += f;
				candif.pop(), popworkq.pop();
			}
			// std::cerr << "? ans = " << ans << '\n';

			// std::cerr << "done3" << '\n';
			// std::cerr << candif.size() << '\n';
			while (!candif.empty()) {
				auto [bonus, f] = candif.top();
				candi.push(f);
				candif.pop();
			}

			// std::cerr << "done4" << '\n';
			while (!popworkq.empty()) {
				auto popq = popworkq.top();
				if (popq == 0) {
					freew++;
				} else {
					workq.push(popq);
					sum += popq;
				}
				popworkq.pop();
			}

			// std::cerr << "done5" << '\n';
			day = r;
		}
		// std::cerr << "? ans = " << ans << '\n';
		ans += sum - tmpsumf;
		// std::cerr << "tmpsumf = " << tmpsumf << '\n';
		// std::cerr << "day " << day << "end ans = " << ans << " sum = " << sum << '\n'; 
		// std::cerr << '\n';
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