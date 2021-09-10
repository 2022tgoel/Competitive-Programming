#include <bits/stdc++.h>
using namespace std;
const int MXN = 21;
const int MX = 2e6;
int N, H, s[MXN], h[MXN], w[MXN];
int dp[MX];
long long height[MX];
int main(){
	ifstream cin ("guard.in");
	ofstream cout ("guard.out");
	cin >> N >> H;
	for (int i = 0; i < N; i++){
		cin >> h[i] >> w[i] >> s[i];
	}
	dp[0] = 2e9+10;
	height[0] = 0;
	int ans = -1;
	for (int mask = 1; mask < (1 << N); mask++){
		dp[mask] = -1;
		for (int j = 0; j < N; j++){
			if ((1<<j)&mask){
				dp[mask] = max(dp[mask], min(dp[mask^(1<<j)]-w[j], s[j]));
				height[mask] = height[mask^(1<<j)]+h[j];
			}
		}
		if (height[mask] >= H){
			ans = max(ans, dp[mask]);
		}
	}
	if (ans == -1) cout << "Mark is too tall";
	else cout << ans << endl;
}
