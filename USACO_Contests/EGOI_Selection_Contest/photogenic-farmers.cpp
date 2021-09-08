#include <bits/stdc++.h>
using namespace std;
const int MXN = 3e5+10;
const int MX = 1e8;
int N;
int a[MXN];
int mn[MXN], mx[MXN];
int main(){
	cin >>N;
	mn[0] = MX;
	for (int i =1; i <= N; i++){
		cin >> a[i];
		mn[i] = min(mn[i-1], a[i]);
	}
	for (int i =N; i>=1; i--){
		mx[i] = max(mx[i+1], a[i]);
	}
	for (int i = 2; i < N; i++){
		for (int j = i+1; j <=N; j++){
			if (a[i] <= a[j]) continue;
			if (mn[i-1] < a[j] && mx[j+1] > a[i]){
				cout << "YES" << endl;
				exit(0);
			} 
		}
	}
	cout << "NO" << endl;
}