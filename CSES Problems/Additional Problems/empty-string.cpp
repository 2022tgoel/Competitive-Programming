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
const int MXN = 501;
const int MOD = 1e9+7;
int dp[MXN][MXN], choose[MXN][MXN];

int add(int x, int y){
	return ((long long)x + y)%MOD;
}
int mul(int x, int y){
	return ((long long)x * y)%MOD;
}

int main(){
	string s; cin >> s;
	int n = s.length();
	choose[0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j =0; j <=i; j++){
			// i choose j
			if (j-1 >= 0) choose[i][j] = choose[i-1][j-1];
			if (j < i) choose[i][j] = add(choose[i][j], choose[i-1][j]);
		}
	}
	for (int i = 0; i < n-1; i++){
		if (s[i] == s[i+1]) dp[i][i+1] = 1;
	}
	for (int k = 3; k<n; k+=2){
		for (int i = 0; i < n-k; i++){
			int j = i+k;
			if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
			for (int l = i+1; l<j; l+=2){
				if (s[i] == s[l]){
					// length is (k+1)/2
					int numl = ((i+1==l) ? 1 : dp[i+1][l-1]);
					int numr = dp[l+1][j];
					//cout << i << ' ' << l << ' ' << numl << ' ' << numr << endl;
					dp[i][j] = add(dp[i][j], mul(mul(choose[(k+1)/2][(l-i+1)/2], numl),numr));
				}
			}
		}
	}
	cout << dp[0][n-1];
}