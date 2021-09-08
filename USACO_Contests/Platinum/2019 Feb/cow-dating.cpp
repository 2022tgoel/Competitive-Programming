#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e6;
int N;
double p[MXN];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);
	cin >> N;
	for (int i= 0; i < N;i++){
		int a; cin >> a; p[i] = a*0.000001;
	}
	double P = 1-p[0];
	double sum = p[0]/P;
	int r = 1;
	double ans = sum*P;
	for (int l= 0; l < N; l++){ //[l,r)
		while (sum < 1 && r<N){
			//shift the right pointer
			sum += p[r] / (1-p[r]);
			P*=(1-p[r]);
			r++;
		}
		ans = max(ans, P*sum);
		//shift left pointer
		P/=(1-p[l]);
		sum -= (p[l]/(1-p[l]));
	}
	cout << (int) (1000000*ans) << endl;
	//.0000006 -> 1 (should be 0)
}