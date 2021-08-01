#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream fout ("x.out");
	int t;
	cin >> t;
	cout << endl;
	for (int j  = 1; j <= t; j++){
		int n;
		cin >> n;
		if (j == 230) fout << n << endl;
		for (int i = 0 ; i < 2*n-2; i++){
			int a, b;
			cin >> a >> b;
			if (j == 230)fout << a << ' ' << b << endl;
		}
	}
}