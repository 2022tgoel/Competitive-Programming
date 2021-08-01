
/*
9
10 12 2 5
1 1 2 2
52 311 13 27
1000000000 1000000000 1 1
1000000000 1 1 1000000000
1 1000000000 1000000000 1
1 2 1 1
7 8 1 2
4 1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
int t;
int x, y, a, b; 
bool check(int s){
	if (x-(long long)s*b < 0) return false; //even taking smaller won't work
	int m = min((x-s*b)/(a-b), s); //can't divide by 0;
	return (long long)(s-m)*a + (long long)m*b <= y;
}

int solve(){
	int lo = 0; int hi = 1e9+10;
	while (lo+1 < hi){
		int mid = (lo+hi)/2;
		if (check(mid)){
			lo = mid;
		}
		else hi = mid;
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int i= 0; i < t; i++){
		cin >> x >> y >> a >> b;
		if(a == b){
			cout << min(x, y)/a <<endl;
			continue;
		}
		if (a < b) swap(a, b);
		cout << solve() << endl;
	}
}