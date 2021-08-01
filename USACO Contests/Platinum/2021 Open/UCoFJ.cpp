#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+10;
int N, breed[MXN], nxt[MXN], last[MXN];


struct LazySegTree {
	long long st[4*MXN], lazy[4*MXN], active[4*MXN];
	void prop(int ind){
		/*
		update the children using the lazy value
		children should be correct after this is done
		*/
		st[ind<<1] += lazy[ind]*active[ind<<1];
		st[(ind<<1)+1] += lazy[ind]*active[(ind<<1)+1];
		lazy[ind<<1] += lazy[ind];
		lazy[(ind<<1)+1] += lazy[ind];
		lazy[ind] = 0;
	}
	void updRange(int a, int b, int delta, int ind=1, int l=1, int r=N){
		if (l > b || r < a) return;
		else if (l >= a && r<=b){
			st[ind]+=delta*active[ind];
			lazy[ind]+=delta; //how much you need to update the children
		}
		else {
			prop(ind);
			int mid = (l+r)/2;
			updRange(a, b, delta, ind<<1, l, mid);
			updRange(a, b, delta, (ind<<1)+1, mid+1, r);
			st[ind] = st[ind<<1] + st[(ind<<1)+1];
		}
	}
	void updSingle(int a, int ind=1, int l=1, int r=N){
		if (l > a || r < a) return;
		else if (l ==a && r==a){
			assert(active[ind] == 0 && st[ind]==0);
			active[ind] += 1;
			st[ind] +=lazy[ind];
		}
		else {
			prop(ind);
			int mid = (l+r)/2;
			updSingle(a, ind<<1, l, mid);
			updSingle(a, (ind<<1)+1, mid+1, r);
			active[ind] = active[ind<<1] + active[(ind<<1)+1];
			st[ind] = st[ind<<1] + st[(ind<<1)+1];
		}
	}
	long long qrySum(int a, int b, int ind=1, int l=1, int r=N){
		if (l > b || r < a) return 0;
		else if (l>=a && r<=b) return st[ind];
		else {
			prop(ind);
			int mid = (l+r)/2;
			long long x = qrySum(a, b, ind<<1, l, mid);
			long long y = qrySum(a, b, (ind<<1)+1, mid+1, r);
			return x+y;
		}
	}

} segtree;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> breed[i];
	fill(last+1, last+N+1, N+1);
	for (int i = N; i > 0; i--){
		nxt[i] = last[breed[i]]; // N+1 if last instance 
		last[breed[i]] = i;
	}
	// init 
	set<int> visited;
	for (int i  = 1; i <= N; i++){
		if (!visited.count(breed[i])){
			segtree.updSingle(i);
			if (i+1 <= nxt[i]-1)segtree.updRange(i+1, nxt[i]-1, 1);
			visited.insert(breed[i]);
		}
	}
	//
	long long ans = 0;
	
	
	for (int i = 1; i <=N;i++){ // i is the pos of the left leader
		if (i+1 <= nxt[i]-1) {
			segtree.updRange(i+1, nxt[i]-1, -1); //can no longer be a middle leader
			/*
			for (int j = 1; j <=N; j++){
				cout << segtree.qrySum(j, j) << ' ';
			}
			cout << endl;
			*/
			ans+=segtree.qrySum(i+1, nxt[i]-1);

		}
		if (nxt[i]!=N+1) segtree.updSingle(nxt[i]);
		if (nxt[i]+1 <= nxt[nxt[i]]-1){
			segtree.updRange(nxt[i]+1, nxt[nxt[i]]-1, 1); 
		}
		//cout << "final " << i << ' ' << ans << endl;
		
	}
	cout << ans << endl;
}