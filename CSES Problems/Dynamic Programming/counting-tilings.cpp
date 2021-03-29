/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways you can fill an n×m grid using 1×2 and 2×1 tiles.

Input

The only input line has two integers n and m.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤10
1≤m≤1000
Example

Input:
4 7

Output:
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1000][1024];
const int MOD = 1e9+7;

void gen_masks(vector<int>& masks, int mask, int i){
	for(int x = i; x < n-1; x++){
		if ((mask&(1<<x)) && (mask&(1 << (x+1)))){
			//you can remove this
			int nmask =mask^(1 << x)^(1 << (x+1));
			masks.push_back(nmask);
			gen_masks(masks, nmask, x+2);
		}
	}
}

int main(){
	cin >> n >> m;
	for (int mask = 0; mask < (1<<n); mask++){
		//there is one way if all the 0 segments in the mask are even length
		int seg = 0;
		dp[0][mask] = 1;
		for (int i = 0; i < n; i++){
			if (!(mask&(1<<i))) seg++;
			else {
				if (seg&1){
					dp[0][mask] = 0; break;
				}
				seg = 0;
			}
		}
		if (seg&1){
			dp[0][mask] = 0;
		}
		//cout << 0 << ' ' << mask << ' ' << dp[0][mask] << endl;
	}
	
	for (int c =1; c < m; c++){
		for (int mask = 0; mask < (1<< n); mask++){
			int opp = 0;
			for (int i = 0; i < n; i++) 
				if (!(mask&(1<<i))) opp|=(1<<i);
			vector<int> masks;
			masks.push_back(opp);
			gen_masks(masks, opp, 0);
			for(int m : masks){
				dp[c][mask] = ((long long)dp[c][mask] + dp[c-1][m])%MOD;
			}
			//cout << c << ' ' << mask << ' ' << dp[c][mask] << endl;
		}
	}
	cout << dp[m-1][0];
}