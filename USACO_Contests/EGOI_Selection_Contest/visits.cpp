#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
const int MX = 1e9+1;
int N;
int a[MXN], v[MXN];
long long cycle(){
	//only works for subtask 2 currently
	int cur = 1;
	int visit = 0;
	long long ans = 0;
	int mn = MX;
	//for negative parts
	int l = 0; // length of the current negative part
	long long c1 = 0; 
	long long c2 = 0;
	//
	while (visit < N){
		int cost = v[cur];
		mn = min(cost, mn);
		if (cost < 0){
			l++;
			if (l&1) c2+=cost;
			else c1+= cost;
		} 
		else {
			if (l>0){
				//negative part just ended
				ans+=min(c1, c2);
				l=0; c1=0; c2=0;
			}
			ans+=cost; 

		}
		cur = a[cur];
		visit++;
	}
	return ans - (mn > 0 ? mn : 0);
}
int main(){
	cin >> N;
	long long ans = 0;
	int mn = MX;
	for (int i =1 ; i <= N; i++){
		cin >> a[i]  >> v[i];
		ans= ans+v[i];
		mn= min(mn, v[i]);
	}
	cout << ans - mn << endl;
}