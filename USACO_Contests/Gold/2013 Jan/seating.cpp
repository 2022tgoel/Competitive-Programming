#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
const int MXN = 5e5+10;
using namespace std;

int N, M;

struct LazySegTree {
	pair<int, pii> st[MXN][3];

	void updNode(int k){
		//update node given updated decsendants
		auto left = st[k<<1];
		auto right = st[(k<<1)+1];
		st[k][0] = left[0];
		st[k][2] = right[2];
		pair<int, pii> m = {left[2].f + right[0].f, {left[2].s.f, right[0].s.s}};
		st[k][1] = max(max(left[1], right[1]), m);
	}

	void build(int k=1, int l=0, int r=N-1){
		//buld with everything empty
		if (l==r){
			pair<int, pii> x = {1, {l, r}}
			for (int i =0; i < 3; i++) st[1] = x;
		}
		int mid = (l+r)/2;
		build(k<<1, l, mid);
		build((k<<1)+1, mid+1, r);
		updNode(k);
	}
	pii qry(int sz, int k=1, int l=0, int r=N-1){
		//qry where to place with size
		if (st[k][1].f < sz){
			return {N, N}; //impossible
		}
		else{
			int mid = (l+r)/2;
			pii x = qry(sz, k<<1, l, mid);
			if (x.f == N) {
				//impossible to do with left
				x = qry(sz, (k<<1)+1, mid+1, r);
			}
			return min(x, st[k][1].s); //best one that straddles
		}

	}
	void upd(int a, int b, int val, int k=1, int l=0, int r=N-1){

	}
} segtree;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> N >> M;
	int ans = 0;
	for (int i = 0; i < M; i++){
		char t; cin >> t;
		if (t=='A'){
			int sz; cin >> sz;
			int a = segtree.qry(sz);
			if (a == -1){
				ans++;
			}
			else segtree.upd(a, a+sz-1, 1);
		}
		else{
			int a, b; cin >> a >> b; a--; b--;
			segtree.upd(a, b, -1);
		}
	}
}