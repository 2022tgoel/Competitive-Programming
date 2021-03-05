#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
const int MOD = 1e9+7;
string inp;
int arr[MXN];
int dp[MXN][4][4][4];
int main(){
	cin >> inp;
	int n = inp.length();
	for (int i = 0; i < inp.length(); i++){
		char c = inp[i];
		if (c == 'A') arr[i] = 0;
		else if (c == 'G') arr[i] = 1;
		else if (c == 'C') arr[i]= 2;
		else if (c == 'T') arr[i] = 3;
		else arr[i] = 4;
	}
	if (arr[0] == 4){
		for (int x = 0; x < 4; x++){
			for (int a = 0; a < 4; a++)
				dp[0][a][x][x] = 1;
		}
	}
	else
		for (int a = 0; a < 4; a++)
			dp[0][a][arr[0]][arr[0]] = 1; //1 way to split first part
	for (int i = 1; i < inp.length(); i++){
		int cur = arr[i];
		for (int a = 0; a < 4; a++){
			for (int b = 0; b < 4; b++){
				for (int c = 0; c < 4; c++){
					//if (dp[i-1][a][b][c]!=0) cout << i-1 << ' ' << a << ' ' << b << ' ' << c << ' ' << dp[i-1][a][b][c] << endl;
					if (cur == 4){
						for (int pc = 0; pc < 4; pc++) {
							if (pc!=c) dp[i][a][b][pc] += dp[i-1][a][b][c];
							dp[i][a][b][pc]%=MOD;
							if (c==a) dp[i][b][pc][pc] += dp[i-1][a][b][c];
							dp[i][b][pc][pc]%=MOD;
						}
					}
					else {
						if (cur!=c) dp[i][a][b][cur] += dp[i-1][a][b][c];
						dp[i][a][b][cur]%=MOD;
						if (c == a) dp[i][b][cur][cur]+=dp[i-1][a][b][c];
						dp[i][b][cur][cur]%=MOD;
					}
					

				}
			}
		}
	}
	int ans = 0;
	for (int a = 0; a < 4; a++){
			for (int b = 0; b < 4; b++){
				for (int c = 0; c < 4; c++){
					if (a == c) ans+=dp[n-1][a][b][c];
					ans%=MOD;
				}
			}
	}
	cout << ans;
}