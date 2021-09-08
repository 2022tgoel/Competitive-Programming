#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+10;
int N, arr[MXN], bit[MXN];
int upd(int i){
	while (i <=N){
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
	ifstream cin("sleepy.in");
	ofstream cout("sleepy.out");
	cin >> N;
	for (int i = 0; i < N; i++) cin>> arr[i];
	int back = N-1; //back..N-1 is sorted
	upd(arr[back]);
	while (back-1 >=0 && arr[back] > arr[back-1]){
		back--;
		upd(arr[back]);
	}
	cout << back << endl;
	for (int i = 0; i<back ; i++){
		int count = qry(N) - qry(arr[i]-1);
		cout << N-1-count;
		if (i !=back-1) cout << ' ';
		upd(arr[i]);
	}
}