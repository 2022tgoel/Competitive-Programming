#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5;
unordered_set<int> xors; 
bool check(int num, int i){
	unordered_set<int> n;
	int mask = 0;
	for (int j = 29; j>=i; j--){
		mask+=(1<<j); // this bit is on
	}
	for (int x : xors){
		n.insert(x&mask); // this with the end chopped off
	}
	for (int x : n){
 		if (n.count(x^num)) return true;
	}
	return false;
}
int a[MXN];
int main(){
	//ifstream cin("in.in");
	int n; cin >> n;
	int x = 0;
	xors.insert(0);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		x^=a[i];
		xors.insert(x);
	}
	int ans = 0;
	for (int i = 29; i >=0; i--){
		if (check(ans + (1<<i), i)){
			ans+=(1<<i);
		}
		//cout << ans << endl;
	}
	cout <<  ans << endl; 
}