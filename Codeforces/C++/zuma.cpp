/*
B. Zuma
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Genos recently installed the game Zuma on his phone. In Zuma there exists a line of n gemstones, the i-th of which has color ci. The goal of the game is to destroy all the gemstones in the line as quickly as possible.

In one second, Genos is able to choose exactly one continuous substring of colored gemstones that is a palindrome and remove it from the line. After the substring is removed, the remaining gemstones shift to form a solid line again. What is the minimum number of seconds needed to destroy the entire line?

Let us remind, that the string (or substring) is called palindrome, if it reads same backwards or forward. In our case this means the color of the first gemstone is equal to the color of the last one, the color of the second gemstone is equal to the color of the next to last and so on.

Input
The first line of input contains a single integer n (1 ≤ n ≤ 500) — the number of gemstones.

The second line contains n space-separated integers, the i-th of which is ci (1 ≤ ci ≤ n) — the color of the i-th gemstone in a line.

Output
Print a single integer — the minimum number of seconds needed to destroy the entire line.
*/

#include <bits/stdc++.h>
using namespace std;
int N; 
const int MXN = 510;
const int MX = 1000;
int a[MXN], dp[MXN][MXN];
int main(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			if (i==j) dp[i][j] = 1;
			else dp[i][j] = MX;
		}
	}
	for (int k = 1; k < N; k++){
		for (int i = 0; i < N-k; i++){
			int j = i+k;
			if (a[i] == a[j]) {
				if (k > 1) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1;
			}
			for (int m = i; m <j; m++) dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
		}
	}
	cout << dp[0][N-1];
}	