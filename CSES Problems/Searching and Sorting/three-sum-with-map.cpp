//too slow - TLE on two of the CSES test cases
#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
int N, X, a[5000];
unordered_map<int, int> vals;
unordered_map<int, pair<int, int>> pairs;
int main(){
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		vals[a[i]] = max(vals[a[i]], i+1);
	}
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			int sum = a[i] + a[j];
			if (vals[X-sum]!=0 && vals[X-sum] > j+1) {
				cout << i+1 << ' ' << j+1 << ' ' << vals[X-sum];
				exit(0);
			}
		}
	}
	
	cout << "IMPOSSIBLE";
}