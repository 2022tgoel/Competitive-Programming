#include <bits/stdc++.h>
using namespace std;
const int MXN = 310;
const int MX = 1e8;
int N, c[MXN], dp[MXN][MXN][MXN]; //i, j, base
int main(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i];
	for (int i = 0; i < N;i++){
		for (int j = i; j<N; j++){
			for (int b = 1; b <= N; b++) dp[i][j][b] = MX;
		}
	}
	for (int i = 0; i < N; i++){
		for (int b = 1; b<=N; b++){
			dp[i][i][b] = 2;
			if (b == c[i]) dp[i][i][b]--;
		}
	}
	for (int k = 1; k < N; k++){
		for (int i = 0; i < N-k; i++){
			int j = i+k;
			int best = MX;
			for (int b = 1; b<=N; b++){
				//dp[i][j][b] = min(dp[i][j][b], dp[i+1][j][b] + (b ==c[i]? 0 : 1)) 
				for (int x = i; x<j; x++){
					dp[i][j][b] = min(dp[i][j][b], dp[i][x][b] + dp[x+1][j][b] - 1);
				}
				best =min(best, dp[i][j][b]);
				//cout << i << ' ' << j << ' ' << b << ' ' << dp[i][j][b] << endl;
			}
			for (int b = 1; b<=N;b++){
				dp[i][j][b] = min(dp[i][j][b], best+1);
			}
		}
	}
	int ans = MX;
	for (int b = 1; b<=N; b++) ans = min(ans, dp[0][N-1][b]);
	cout << ans;
}