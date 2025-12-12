#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n;
	string s;
	cin >> T;
	while(T--){
		cin >> n >> s;
		s = '0' + s;
		if(s[n] == '0' && s[n - 1] == '0'){
			cout << "Yes\n";
			continue;
		}
		int fi = 0;
		int tmp = 0;
		for(int i = 1;i <= n;++i){
			if(s[i] == '1') ++tmp;
			else {
				if(tmp) --tmp;
				else fi = i;
			}
		}
		int ans = 0;
		std::cerr << fi << " " << n << '\n';
		if(n - fi >= 4) ans = 2;
		if(ans >= 2 )cout << "Yes\n";
		else cout << "No\n";
//		int cnt = 0;
//		for(int i = n;i;--i) if(s[i] == '0'){
//			if(s[i - 1] == '0') break;
//			else ++cnt;
//		}
//		if(cnt >= 2) cout << "Yes\n";
//		else cout << "No\n";
	}
}