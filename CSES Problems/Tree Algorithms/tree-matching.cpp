#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int N;
vector<int> edges[MXN];
int dp[MXN][2];
bool viz[MXN];
void calc(int cur){
	//cout << cur << viz[cur] << endl;
	viz[cur] = true;
	vector<int> child;
	for (int e : edges[cur]){
		if (viz[e]) continue;
		calc(e);
		child.push_back(e);
	}
	for (int c : child){
		dp[cur][1] += max(dp[c][0], dp[c][1]);
	}
	for (int c : child){
		dp[cur][0] = max(dp[cur][0], dp[c][1] + 1 + dp[cur][1] - max(dp[c][0], dp[c][1]));
	}

}
int main(){
	cin >> N;
	for (int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b); edges[b].push_back(a);
	}
	calc(1);
	cout << max(dp[1][0], dp[1][1]);
}