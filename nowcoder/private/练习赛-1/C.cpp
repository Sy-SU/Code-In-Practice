#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
	int n;
	std::cin >> n;
 
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
 
	std::set<int> s;
    int sz = s.size();
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
        if (a[i] && sz == s.size()) {
            std::cout << -1 << '\n';
            return;
        }
        sz = s.size();
    }
    
    int max = *std::max_element(s.begin(), s.end());
    if (max > sz) {
    	std::cout << -1 << '\n';
    	return;
    }

    int lacki = -1;
    if (max == sz) {
    	for (int i = 1; i <= n; i++) {
    		if (a[i] == max) {
    			lacki = i;
    			break;
    		}
    	}
    }

    std::vector<int> o(n + 1);
    if (lacki != -1) {
        std::vector<int> b = a;
        std::sort(b.begin() + 1, b.end());

        b[0] = -1;

        int lacknum = -1;
        for (int i = 1; i <= n; i++) {
            if (b[i] == b[i - 1] + 2) {
                lacknum = b[i - 1] + 1;
            }
        }

    	for (int i = 1; i <= n; i++) {
            o[a[i]] = i;        
        }

        o[lacknum] = lacki;
        
        std::cout << max << '\n';
        for (int i = 1; i <= max; i++) {
            std::cout << o[i] << " \n"[i == max];
        }
    } else {
    	for (int i = 1; i <= n; i++) {
    		o[a[i]] = i;
    	}

    	std::cout << max << '\n';
    	for (int i = 1; i <= max; i++) {
    		std::cout << o[i] << " \n"[i == max];
    	}
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
