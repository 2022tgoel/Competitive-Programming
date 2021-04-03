#include <bits/stdc++.h>

using namespace std;
const int MXN = 1e6+1;
const int MOD = 1e9+7;
int dp[MXN][2];
int main(){
	int s1 = 1;
	int s2 = 1;
	for (int i = 1; i <MXN; i++){
		dp[i][0] = s1;
		dp[i][1] = s2;
		s1=((long long)s1 + dp[i][0] +dp[i][1])%MOD;
		s2=(4*(long long)s2+dp[i][0])%MOD;
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >>n;
		cout << (dp[n][0] + dp[n][1])%MOD << endl;
	}
}