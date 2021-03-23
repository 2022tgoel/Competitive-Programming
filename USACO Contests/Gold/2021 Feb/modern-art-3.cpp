#include <bits/stdc++.h>
using namespace std;
const int MXN = 310;
const int MX = 1e8;
int N, c[MXN], dp[MXN][MXN]; //i, j
int main(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> c[i];
	for (int i = 0; i < N;i++){
		for (int j = i; j<N; j++){
			if (i==j) dp[i][j] = 1;
			else dp[i][j] = MX;
		}
	}
	for (int k = 1; k < N; k++){
		for (int i = 0; i < N-k; i++){
			int j = i+k;
			if (c[i] == c[j]) dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
			for (int m = i; m < j; m++){
				dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
			}
		}
	}
	cout << dp[0][N-1];
}