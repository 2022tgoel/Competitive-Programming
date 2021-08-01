#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n; cin>>n;
		vector<int> a(n);
		int mx = 0;
		int sm = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i]; mx = max(a[i], mx); sm +=a[i];
		}
		if (2*mx > sm) cout << "T" << endl;
		else {
			if ((sm-2*mx)%2 == 1) cout << "T" << endl;
			else cout << "HL" << endl;
		}
	}
}