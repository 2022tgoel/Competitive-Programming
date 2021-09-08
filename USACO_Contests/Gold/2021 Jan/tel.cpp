#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MX = 1e8;
const int MXN = 5e4+20;
vector<int> breeds[60];
set<int> come[60];
int d[60], left[60];
bool v[60];
int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> b[i];
		b[i]-=1;
		d[i] = MX;
		left
	}
	for (int i = 0; i < k; i++){
		string s;
		cin >> s;
		for (int j = 0; j < k; j++){
			if (s[j] == '1'){
				breeds[i].push_back(j);
				come[j].insert(i);
			}
		}
	}
	queue<int> q; //bfs of the breeds you can go to
	//if distance is 0 at end, no way to get there
	q.push(b[0]);
	v[b[0]] = true;
	d[0] = 0;

	while(!q.empty()){
		int cur = q.front(); q.pop();
		vector<int> bleft(n);
		vector<int> bright(n);
		for (int child : breeds[cur]){
			//cout << child << v[child] << endl;
			if (v[child]) continue;
			q.push(child);
			v[child] = true;
		}
	}
	cout << (d[n-1] == MX ? -1 : d[n-1]);

}