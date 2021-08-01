#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5;
int N, dishes[MXN];
bool top[MXN];

set<int> added;
int main(){
	ifstream cin ("dishes.in");
	ofstream cout ("dishes.out");
	cin >> N;
	for (int i = 0; i < N; i++) cin >> dishes[i];
	added.insert(dishes[0]);
	top[0] = true;
	int lb = 0;
	for (int i = 0; i < N; i++){
		if (dishes[i] < lb) {
			cout << i << endl;
			exit(0);
		}
		auto x = added.upper_bound(dishes[i]);
		//cout << *x;
		if (x == added.end()){
			//lowest number, just make new pile
			added.insert(dishes[i]);
			top[dishes[i]] = true;
			//cout << "Here";
		}
		else {
			if (!top[*x]){
				auto it = added.begin();
				vector<int> vals;
				while (*it < dishes[i]){
					//cout << *it << "hi"<< endl;
					vals.push_back(*it);
					lb = *it; //no dish vlaue can be lower than this
					it++;
				}
				for (int a : vals){
					added.erase(a);
				}
				added.insert(dishes[i]);
				top[dishes[i]] = true;
				//cout << "Here1";
			}
			else{
				added.insert(dishes[i]);
				top[dishes[i]] = true;
				top[*x] = false;
				//cout << "Here2";
			}
		}
 	}
}