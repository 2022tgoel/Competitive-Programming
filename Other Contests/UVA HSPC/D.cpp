#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int b = 0; b < t; b++){
		int m; cin >> m;
		vector<int> goes(100);
		for (int i = 0; i < 100; i++){
			goes[i] = i;
		}
		for (int i = 0; i < m; i++){
			int o; int d; string s;
			cin >> o >> s >> d;
			goes[o] = d;
		}
		int k; cin >> k;
		int pos = 0;
		bool done = false;
		for (int i =0; i< k;i++){
			int r; cin >> r;
			pos= min(pos+r, 99);
			while (goes[pos]!=pos) pos = goes[pos];
			if (goes[pos] == 99){
				cout << i+1 << endl;
				done = true; break;
			}
		}
		if (!done) cout <<"Still playing!" << endl;
	}
}	