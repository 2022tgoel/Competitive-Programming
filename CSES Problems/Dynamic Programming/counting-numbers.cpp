#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[19];
ll nine[19];
ll count(ll x){
	if (x < 0) return 0;
	if (x == 0) return 1;
	vector<int> digits;
	ll div = 1e18;
	ll l = x;
	while (div!=0){
		if (div <= x){
			digits.push_back(l/div);
			l-=(l/div)*div;
		}
		div/=10;
	}
	ll c = 0;
	for (int i = 0; i < digits.size(); i++){
		unordered_set<int> p;
		for (int d = 0; d <=digits[i]; d++) p.insert(d);
		if (i == 0) p.erase(0);
		if (i < digits.size()-1) p.erase(digits[i]);//cannot be digits[i], that will be counted later
		if (i > 0) p.erase(digits[i-1]);
		c+= p.size()*nine[digits.size()-1-i];
		if (i > 0 && digits[i] == digits[i-1]) break;
	}
	return c + dp[digits.size()-1];
}

int main(){
	ll x, y; cin >> x >> y;
	dp[0] = 1;
	nine[0] = 1;
	for (int i = 1; i <=18; i++) {
		nine[i]=9*nine[i-1];
		dp[i] = dp[i-1]+nine[i];
	}
	cout << count(y) - count(x-1);
}