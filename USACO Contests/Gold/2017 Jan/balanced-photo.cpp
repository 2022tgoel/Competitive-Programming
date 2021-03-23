#include <bits/stdc++.h>
using namespace std;
int N;
const int MXN = 1e5+10;
set<int> heights;
map<int, int> c;
int bit[MXN], h[MXN], l[MXN], r[MXN];
void upd(int i){
	while(i <= N){
		bit[i]+=1;
		i+=(i&-i);
	}
}
int qry(int i){
	int ans = 0;
	while (i > 0){
		ans+=bit[i];
		i-=(i&-i);
	}
	return ans;
}
int main(){
	ifstream cin("bphoto.in");
	ofstream cout("bphoto.out");
	cin >> N;
	for (int i = 0; i< N; i++){
		cin >> h[i]; heights.insert(h[i]);
	}
	int x = 0;
	for (int height : heights){
		c[height] = ++x;
	}
	for (int i = 0; i < N; i++){
		h[i] = c[h[i]];
	}
	for (int i = 0; i < N; i++){
		l[i] = i - qry(h[i]);
		upd(h[i]);
	}
	memset(bit, 0, sizeof(bit));
	for (int i = N-1; i>=0; i--){
		r[i] = (N-1-i)-qry(h[i]);
		upd(h[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++){
		if (max(r[i], l[i]) > min(r[i], l[i])*2) ans++;
	}
	cout << ans;
}