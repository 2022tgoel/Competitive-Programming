#include <bits/stdc++.h>
#include <iostream>

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, a, b;
		cin >> n >> a >> b;
		if ((b-a) % 2 == 0) cout << abs(b-a)/2;
		else {
			if (n % 2) cout << (n-a+1)/2 + b/2;
			else cout << "Impossible";
		}
	}
}