#include <bits/stdc++.h>
using namespace std;
const int MXN = 501;
int N, M;
int grid[MXN][MXN], dp[MXN][MXN], zero[MXN][MXN], sum[MXN][MXN];
int best[MXN][MXN]; // best rectangle
int main(){
	cin >> N >> M;
	for (int i= 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> grid[i][j];
			sum[i][j] = sum[i][j-1] + grid[i][j];
			zero[i][j] = zero[i][j-1] + (grid[i][j] == 0);
		}
	}
	for (int i = 1; i <=M; i++){
		for (int j =i; j<=M; j++){
			int t = 0;
			for (int k = 1; k <=N; k++){
				if (zero[k][j] - zero[k][i-1] > 0){
					t = 0;
				}
				else t+=sum[k][j] - sum[k][i-1];
				best[i][j] = max(best[i][j], t);
			}
		}
	}
	for (int i = 1; i<=M; i++){
		for (int j = 0; j<=M; j++){
			dp[i][j] = -1; // everything is impossible
		}
	}
	for (int i = 1; i<=M; i++){
		for (int j = 1; j<=M; j++){
			dp[i][j] = dp[i][j-1];
			for (int k = 1;k<=j; k++){
				if (dp[i-1][k-1] !=-1 && best[k][j] > 0) dp[i][j] = max(dp[i][j], dp[i-1][k-1] + best[k][j]);
			}
		}
		cout << dp[i][M] << endl;
	}
}	