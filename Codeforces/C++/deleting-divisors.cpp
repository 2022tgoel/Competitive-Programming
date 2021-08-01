#include <bits/stdc++.h>
using namespace std;
int t;
int p2(int x){
	int c = 0;
	while (x%2==0) {
		x/=2; c++;
	}
	assert(c>=1);
	return x==1 ? c : 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int i= 0 ; i < t; i++){
		int n;cin >> n;
		if (n&1) cout << "Bob" << endl;
		else {
			int x = p2(n);
			if (x==0) cout << "Alice" << endl;
			else {
				if (x&1) cout << "Bob" << endl;
				else cout << "Alice" << endl;
			}
		}

	}
}