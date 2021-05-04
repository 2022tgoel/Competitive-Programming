#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXN = 2e5+1;
int N, arr[MXN];
deque<int> breed[MXN];

int first[4*MXN], lazy[4*MXN];
ll val[4*MXN];


void prop(int k, int l, int r){
	val[k]+=lazy[k]*first[k];
	if (l!=r){
		//push to children
		lazy[(k<<1)] += lazy[k]; lazy[(k<<1)+1] += lazy[k]; 
	}
	if(l!=r || first[k])lazy[k] =0; //the changes have been pushed or put into effect
}

void updFirst(int a, int k=1, int l = 0, int r=N-1){
	prop(k, l, r);
	if (l > a || r < a) return;
	if (a == l && a==r){
		assert(first[k]==0);
		first[k]=1;
		assert(lazy[k] >=0);
		val[k]=lazy[k];
		lazy[k]=0;
		return;
	}
	int mid = (l+r)/2;
	updFirst(a, k << 1, l, mid);
	updFirst(a, (k << 1) +1, mid+1, r);
	first[k] = first[k <<1] + first[(k<<1)+1];
	val[k] = val[(k<<1)] + val[(k<<1)+1];

}

void updRange(int a, int b, int v, int k=1, int l=0, int r=N-1){
	//cout << a << ' ' << b << ' ' << k << ' ' << l << ' ' << r << endl;
	if (l > r) return;
	if (l > b || r < a) return;
	else if (l>=a && r<=b) {
		lazy[k] += v; 
		prop(k, l, r);
		return;
	}
	int mid = (l+r)/2;
	updRange(a, b, v, k << 1, l, mid);
	updRange(a, b, v, (k << 1) +1, mid+1, r);
	val[k] = val[k << 1] + val[(k << 1)+1];

}

ll qry(int a, int b, int k=1, int l=0, int r=N-1){
	if (l > r) return 0;
	prop(k, l, r);
	if (l > b || r < a) return 0;
	else if (l>=a && r<=b) return val[k];
	int mid = (l+r)/2;
	return qry(a, b, k << 1, l, mid) + qry(a, b, (k << 1) +1, mid+1, r);
}


int main(){
	cin >> N; 
	for (int i =0 ; i < N; i++){
		cin >> arr[i];
		breed[arr[i]].push_back(i);
	}
	for (int i = 1; i<=N; i++){
		if (breed[i].size()==0) continue;
		int f = breed[i].front(); breed[i].pop_front();
		int s = (breed[i].size()==0 ? N : breed[i].front());
		updFirst(f);
		updRange(f+1, s-1, 1);
	}
	ll ans = 0;
	for (int i =0; i < N; i++){
		int b = arr[i]; 
		int s = (breed[b].size()==0 ? N : breed[b].front()); 
		if (breed[b].size()) breed[b].pop_front();
		updRange(i+1, s-1, -1);
		ans+= qry(i+1, s-1); // query range
		if (s<N){
			//there is still an additional instance
			int s2 = (breed[b].size()==0 ? N : breed[b].front());
			updFirst(s);
			updRange(s+1, s2-1, 1);
		}
		cout << i  << ' ' << ans << endl;
	}
	cout << ans << endl;
}