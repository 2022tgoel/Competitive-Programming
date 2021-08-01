#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	cin >> t;
	for (int i = 0; i < t; i++){
		long long n, a, b;
		cin >> n >> a >> b;
		if (n%2){
			long long l = n;
			long long x= abs(b-a);
			long long p;
			if (x %2) p = (l+x)/2;
			else p = x/2; 
			cout << "Graph #" << i+1 << ": " << min(p, l-p) << endl;
		}
		else {
			if ((b-a)% 2) cout << "Graph #" << i+1 << ": " << "Impossible" << endl;
			else {
				long long l = (n+1)/2;
				long long p = abs(b-a)/2;
				cout << "Graph #" << i+1 << ": " << min(p, l-p) << endl;
			}
		}
	}
	return 0;
}