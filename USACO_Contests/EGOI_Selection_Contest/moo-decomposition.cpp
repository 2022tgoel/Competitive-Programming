#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
const int MOD = 1e9+7;
int N;
long long K, L;
string moo;
int choose[MXN];

int p(int x, long long power){
	// x ^ (MOD - 2)
	if (power == 1) return x;
	int y = p(x, power>>1);
	if (power&1){
		return (((long long)y*y)%MOD * x)%MOD;
	}
	else return ((long long)y*y)%MOD;
}

int main(){
	cin >> K >> N >> L >> moo;
	assert(K <= N);
	//calc i choose k
	choose[K] = 1;
	for (int i = K+1; i <=N; i++){
		choose[i] = ((((long long)choose[i-1] * i)%MOD)*p(i-K, MOD-2))%MOD;
		//cout << i << ' ' << choose[i] << endl;
	}
	int ans = 1;
	int co = 0;
	int cm = 0;
	for (int i = N-1; i >=0 ; i--){
		if (moo[i] == 'O'){
			co++;
		}
		if (moo[i] == 'M'){
			int x = co - K*cm;
			assert(x >=K);
			ans = ((long long)ans * choose[x])%MOD;
			cm++;
		}
	}
	//cout << ans << endl;
	cout << p(ans, L) << endl;
}