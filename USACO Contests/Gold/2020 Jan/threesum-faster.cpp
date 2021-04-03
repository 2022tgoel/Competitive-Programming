#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
using namespace std;
const int MXN = 5e4+1;
int N, Q;
long bit[MXN];
int A[MXN];
const int MXQ = 1e5;
pair<pii, int> q[MXQ];
long ans[MXQ];
void upd(int ind, int val){
	while (ind<=N){
		bit[ind]+=val;
		ind+=(ind&-ind);
	}
}
long qry(int ind){
	long ans = 0;
	while (ind>0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int main(){
	ifstream cin("threesum.in");
	ofstream cout("threesum.out");
	cin >> N >> Q; 
	for (int i = 1; i <=N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < Q; i++){
		cin >> q[i].f.s >> q[i].f.f; q[i].s = i;
	}
	sort(q, q+Q);
	int lend = 0;
	for (int i = 0; i < Q; i++){
		int end = q[i].f.f;
		unordered_map<int, int> mp;
		for (int x = end; x >0; x--){
			int y = x+1; // update mp with all the new y,z pairs
			for (int z = max(lend+1, y+1); z <=end;z++){
				mp[A[y] + A[z]]++;
			}
			upd(x, mp[-1*A[x]]);
		}
		lend = end;
		//cout << end << ' ' << qry(end) << ' ' << q[i].f.s-1 << ' ' << qry(q[i].f.s-1) << endl;
		//assert((qry(end) - qry(q[i].f.s-1))%2 == 0);
		ans[q[i].s] = (qry(end) - qry(q[i].f.s-1));
	}
	for (int i = 0; i < Q; i++){
		cout << ans[i] << endl;
	}
}