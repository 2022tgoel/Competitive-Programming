#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+10;
long long stree[4*MXN][4];
int N, M;
// 0 - inside, 1 - inculdes left, 2 - includes right, 3 - total sum
void upd(int i, int val, int k = 1, int l=0, int r=N-1){
	if (i < l || i > r) return;
	if (l==i && r==i) {
		stree[k][0] = max(0, val);
		stree[k][1] = max(0, val);
		stree[k][2] = max(0, val);
		stree[k][3] = val;
		return;
	}
	int mid = (l+r)/2;
	upd(i, val, k<<1, l, mid);
	upd(i, val, (k<<1)+1, mid+1, r);
	stree[k][0] = max(stree[k<<1][0], stree[(k<<1)+1][0]);
	stree[k][0] = max(stree[k][0], stree[k<<1][2] + stree[(k<<1)+1][1]);
	stree[k][1] = max(stree[k<<1][1], stree[k<<1][3] + stree[(k<<1)+1][1]);
	stree[k][2] = max(stree[(k<<1)+1][2], stree[(k<<1)+1][3] + stree[k<<1][2]);
	stree[k][3] = stree[k<<1][3] + stree[(k<<1)+1][3];
}


int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		int a; cin >> a;
		upd(i, a);
	}
	for (int i = 0 ; i < M; i++){
		int k, x; cin >> k >> x; k--;
		upd(k, x);
		cout << stree[1][0]<< endl;
	}
}