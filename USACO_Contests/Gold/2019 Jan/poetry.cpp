#include <bits/stdc++.h>
const int MXN = 5e4+10;
int N, M, K, dp[MXN][MXN], sum[MXN];
vector<int> words[MXN];
map<char, int> rhymes;
int main(){
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++){
		int s, c;
		cin >> s >> c;
		words[c].push_back(s);
	}
	for (int i = 0; i < M;i++) {
		char c;
		cin >> c;
		rhymes[c]++;
	}
	//dp[all classes][0] = 1
	sum[0] = 1; //1 0-syllable word can be made
	
	for (int k =1; k <= K;k++){
		for (int c = 1; c<=N;c++){
			
		}
	}
}