#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXN = 1e5;
const int MOD = 1e9+7;
int N, pw[MXN], delta[2*MXN], num[2*MXN], start[MXN];
int main(){
	ifstream cin ("help.in");
	ofstream cout ("help.out");
	cin >> N;
	pw[0]  = 1;
	for (int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		delta[a]=1;
		delta[b]=-1;
		start[i] = a;
		if (i > 0) pw[i] = ((ll)pw[i-1]*2) % MOD;
	}
	num[0] = delta[0];
	for(int i = 1; i < 2*N; i++) num[i] = num[i-1] + delta[i];
	ll ans = 0;
	for (int i = 0; i < N; i++){
		ans = (ans + pw[N-num[start[i]]]) %MOD;
		//cout << ans << num[start[i]] << endl;
	}
	cout << ans;
}