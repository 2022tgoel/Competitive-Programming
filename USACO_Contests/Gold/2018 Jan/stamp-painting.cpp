#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int MXN = 1e6+10;
int dp[MXN], dpr[MXN];
int N, K, M;
int main(){
	ifstream cin("spainting.in");
	ofstream cout("spainting.out");
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++){
		if (i == 0) dp[i] = M;
		else dp[i] = ((long long)dp[i-1]*M)%MOD;
		if (i == K-1){
			dp[i] = (dp[i] - M + MOD)%MOD;
		}
		else if (i>=K){
			dp[i] = ((dp[i] - (((long long)dp[i-K]*(M-1))%MOD) )+MOD)%MOD;
		}
		//cout << dp[i] << ' ';
	}
	//cout << endl;
	dpr[N] = 1;
	dpr[N-1] = M;
	for (int i = N-2; i >=0;i--){
		dpr[i] = ((long long)dpr[i+1]*M)%MOD;
	}
	int ans = (M*(long long)dpr[K])%MOD;//stuff for 0
	for (int i = 1; i <= N-K; i++){
		//cout << ans << ' ' << dp[i] << ' ' << dpr[i] << endl;
		ans = (ans + (((((long long)dp[i-1]*(M-1))%MOD) * dpr[i+K])%MOD))%MOD;
	}
	cout << ans << endl;
}