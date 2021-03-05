#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;

int main(){
	//mp[0] = 0;
	//mp[-1] = -1;
	cout << ((*--mp.lower_bound(1)).first == 0);
}