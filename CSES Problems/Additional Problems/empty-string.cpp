/*
You are given a string consisting of n characters between a and z.

On each turn, you may remove any two adjacent characters that are equal. Your goal is to construct an empty string by removing all the characters.

In how many ways can you do this?

Input

The only input line has a string of length n.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤500
Example

Input:
aabccb

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int dp[510][510];
void add(int i, int j, int x){
	dp[i][j] = ((long long)dp[i][j] + x)%MOD;
}
int main(){
	string s;
	cin >> s;
	int N = s.size();
	for (int i = 0; i < N-1; i++){
		if (s[i] == s[i+1]) dp[i][i+1] = 1;
	}
	for (int k = 3; k<N; k+=2){
		for (int i = 0; i < N-k; i++){
			int j = i+k;
			//case 1
			if (s[i] == s[j]){
				add(i, j, dp[i+1][j-1]);
			}
			//case 2
			if (s[i] == s[i+1]){
				add(i, j, ((long long)dp[i+2][j]*((k+1)/2))%MOD);
			}
			//case 3
			if (s[j] == s[j-1]){
				add(i, j, ((long long)dp[i][j-2]*((k+1)/2))%MOD);
			}
		}
	}
	cout << dp[0][N-1];
}