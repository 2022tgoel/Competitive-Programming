#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for (int i =0; i < n;i++){
		int m; cin >> m;
		int c = 0;
		bool done = false;
		for (int j = 0; j < m;j++){
			if (done) continue;
			int x; cin >> x;
			c+=x;
			if (c%44==22) {
				cout << "JAIL" << endl;
				done= true;
			}
		}
		if (!done) cout << "SAFE" << endl;
	}
}