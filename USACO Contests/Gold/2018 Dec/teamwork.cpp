#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e4+10;
int n, k;

int s[MXN], dp[MXN];
int main(){
	ifstream fin("teamwork.in");
	ofstream fout("teamwork.out");
	fin >> n >> k;
	for (int i = 0; i < n; i++){
		fin >> s[i];
	}
	dp[0] = s[0];
	for (int i = 1; i < n; i++){
		int mx = s[i];
		for(int b = 0; b < min(i+1, k); b++){
			dp[i] = max(dp[i], (b+1)*mx + (i-b-1 >=0 ? dp[i-1-b] : 0));
			mx = max(mx, s[i-b-1]);
		}
	}
	fout << dp[n-1];
}