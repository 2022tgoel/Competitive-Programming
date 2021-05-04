#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >>t;
	for (int a = 0; a < t; a++){
		int m; cin >> m;
		vector<int> odd(m+1);
		vector<int> even(m+1);
		for (int i = 0; i <=m; i++){
			odd[i] = 0; even[i] = 0;
		}
		for (int i = 1; i <= m; i++){
			int x; cin >> x;
			odd[i] = odd[i-1];
			even[i] = even[i-1];
			if (i%2) odd[i]+=x;
			else even[i]+=x;
		}
		int ans = 0;
		for (int i = 1 ;i<=m; i++){
			if (i%2) ans= max(ans, odd[m] - odd[i-1] + even[i-1]);
			else ans= max(ans, even[m] - even[i-1] + odd[i-1]);
		}
		cout << ans << endl;
	}
}