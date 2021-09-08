#include <bits/stdc++.h>

using namespace std;
const int MXN = 1e4+1;
int N, M;
vector<int> primes;
bool comp[MXN];
int dp[MXN][2];

void add(int ind, int i, int val, int mul){
	dp[ind][i] = (dp[ind][i]+ ((long long)val)*mul)%M;
}

int main(){
	ifstream cin("exercise.in");
	ofstream cout("exercise.out");
	cin >> N >> M;
	for (int i = 2; i <=N; i++){
		if (!comp[i]) primes.push_back(i);
		for (int j = i; j <=N; j+=i) comp[j] = true;
	}
	dp[0][0] = 1;
	for(int i = 0; i < primes.size(); i++){
		for (int j = 0; j <=N; j++) dp[j][(i+1)%2] = dp[j][i%2];
		for (int j = primes[i]; j <=N; j++){
			int x = primes[i];
			while (j-x >=0){
				add(j, (i+1)%2, dp[j-x][i%2], x);
				x*=primes[i];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <=N; i++) {
		ans = ((long long)ans + dp[i][primes.size()%2])%M;
	}
	cout << ans;
}