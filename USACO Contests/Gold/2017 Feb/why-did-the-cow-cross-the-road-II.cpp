#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
int N;
set<int> go[MXN];
int b1[MXN];
int f2[MXN];
int dp[MXN];

int bit[MXN];
void upd(int ind, int val){
	while (ind<=N){
		bit[ind] = max(bit[ind], val);
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind > 0){
		ans = max(ans, bit[ind]);
		ind-=(ind&-ind);
	}
	return ans;
}

int main(){
	ifstream cin("nocross.in");
	ofstream cout("nocross.out");
	cin >> N;
	for (int i = 1; i<=N; i++){
		cin >> b1[i]; //breed by field
	}
	for (int i = 1; i<=N; i++){
		int a; cin >> a;
		f2[a] = i; //field by breed	
	}
	for (int i = 1; i <=N; i++){
		for (int j = max(i-4, 1); j <= min(i+4, N); j++){
			go[i].insert(f2[j]); // breed i can go to these fields
		}
	}
	for (int f = 1; f<=N; f++){
		int b = b1[f];
		for (auto it = go[b].rbegin(); it!= go[b].rend(); it++){
			int dest = *it;
			int x= qry(dest-1)+1;
			upd(dest, x);
		}
	}
	cout << qry(N) << endl;


}