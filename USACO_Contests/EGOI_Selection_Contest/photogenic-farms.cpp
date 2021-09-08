#include <bits/stdc++.h>
using namespace std;
const int MXN = 3e5+10;
const int MX = 1e8;
int N;
int h[MXN];
int mn[MXN], mx[MXN];
int loc[MXN]; // location of farmer with height i

//segment tree
int maxt[4*MXN];

void upd(int a, int val, int k=1, int l=1, int r=N){
	//cout << k << ' ' << l << ' ' << r << ' ' << endl;
	if (r < a || l > a) return;
	if (a==l && a==r){
		assert(maxt[k] == 0);
		maxt[k] = val; //goes from 0 to val
		return;
	}
	int mid = (l+r)/2;
	upd(a, val, k<<1, l, mid);
	upd(a, val, (k<<1)+1, mid+1, r);
	maxt[k] = max(maxt[k<<1], maxt[(k<<1)+1]);
}

int qry(int a, int b, int k=1, int l=1, int r=N){
	if (a > b) return 0;
	if (l > b || r < a) return 0;
	if (l>=a && r<=b){
		return maxt[k];
	}
	int mid = (l+r)/2;
	return max(qry(a, b, k<<1, l, mid), qry(a, b, (k<<1)+1, mid+1, r));
}



int pos_greatest(int height){
	//find the rightmost position with value greater that height
	int lo = 1; int hi = N+1; // [lo, hi)
	while (lo < hi-1){
		int mid = (lo+hi)/2;
		if (mx[mid] > height){
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;

}

int main(){
	cin >>N;
	mn[0] = MX;
	for (int i =1; i <= N; i++){
		cin >> h[i];
		mn[i] = min(mn[i-1], h[i]);
		loc[h[i]] = i;
	}
	for (int i =N; i>=1; i--){
		mx[i] = max(mx[i+1], h[i]);
	}
	for (int i = 1; i <=N; i++){
		//i is the current height -> this is the 2nd farmer
		int pos = loc[i]; 
		if (pos == N) continue;
		int lower = mn[pos-1];
		if (lower < i) {
			int pg = pos_greatest(i);
			if (pg > pos){
				//segment tree query pos+1 to pg-1 for the max
				//cout << (pos+1)<< ' ' << pg-1 << endl;
				int third = qry(pos+1, pg-1);
				if (third > lower){
					cout << "YES" << endl;exit(0);
				}
			}
		}
		//cout << pos << ' ' << i << endl;
		upd(pos, i);
	}
	cout << "NO" << endl;
 
}