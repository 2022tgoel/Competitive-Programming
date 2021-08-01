#include <bits/stdc++.h>
using namespace std;
const int MXN =2e5+10;
const int MOD = 1e9+7;
int N, M, L, R;
int blck[MXN];
int pref[MXN], dp[MXN];
long long net[MXN]; //net probability change

int pw(int x, int pow){
	if (pow == 1) return x;
	int y = pw(x, pow>>1);
	if (pow&1) {
		return ((((long long)y*y)%MOD)*x)%MOD;
	}
	else return (((long long)y*y)%MOD);
}

int prob(int p, int q){
	return ((long long)p*pw(q, MOD-2))%MOD;
}

int mul(int p1, int p2){
	return ((long long)p1*p2)%MOD;
}

int main(){
	//cout << pw(2, MOD-2) << endl; 
	cin >> N >>  M >> L >> R;
	if ((L==0) && (R==0)) {
		cout << 0;
		return 0;
	}
	if (L==0) L=1;
	for (int i = 0; i < M ;i++){
		int a; cin >> a;
		blck[a]=1;
	}
	for (int i = 1; i <=2*N+1; i++){
		pref[i] = pref[i-1] +blck[i];
	}
	//for (int i = 1; i <=N; i++) cout << pref[i] << endl;
	dp[1] = 1;
	int probChange = 0;
	for (int i =1; i <=N; i++){
		probChange=(probChange+net[i]+MOD)%MOD; //sum of all the net changes
		if (blck[i]){
			continue;
		}
		dp[i] = (dp[i] + probChange)%MOD;
		//calc future
		//cout << i << ' ' << dp[i] << endl;
		int canGo = (R-L+1) - (pref[i+R] - pref[i+L-1]);
		//cout << canGo << endl;
		net[i+L]=(net[i+L] + mul(dp[i], prob(1, canGo)))%MOD;
		net[i+R+1]=(net[i+R+1] - mul(dp[i], prob(1, canGo)))%MOD;
	}
	cout << dp[N];
}