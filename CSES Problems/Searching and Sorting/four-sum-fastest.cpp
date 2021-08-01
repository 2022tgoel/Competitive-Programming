//this one passes all test cases
#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
int N, X, a[1010];
unordered_map<int, pii> late; 
unordered_map<int,int>mp;

int main(){
	late.reserve(1024);
	late.max_load_factor(0.25);
	cin >> N >> X;
	for (int i = 0; i < N;i++){
		cin >> a[i];
	}
	for (int i = 0;i< N;i++){
		for (int j =i+1; j < N; j++){
			int sum = a[i] + a[j];
			if (late.count(sum) == 0) late[sum] = make_pair(i+1, j+1);
			else late[sum] = max(late[sum], make_pair(i+1, j+1));
		}
	}
	for (int i = 0;i< N;i++){
		for (int j =i+1; j < N; j++){
			int target = X-a[i]-a[j];
			if (late.count(target)!=0 && j+1 < late[target].f){
				cout << i+1<< ' ' << j+1 << ' ' << late[target].f << ' ' << late[target].s << endl; return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}