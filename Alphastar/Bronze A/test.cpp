#include <bits/stdc++.h>

using namespace std;

vector<int> arr, arr2;
int main(){
	arr.push_back(1);
	arr2 = arr;
	arr2[0] = 5;
	cout << arr[0] << endl;
}