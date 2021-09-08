#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+10;
int N, arr[MXN];
int bit[MXN];
deque<int> breeds[MXN];
void upd(int ind){
	while (ind<=N){
		bit[ind]+=1;
		ind+=(ind&-ind);
	}
}
int qry(int ind){
	int ans = 0;
	while (ind > 0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int main(){
	cin >> N;
	for (int i = 1; i <=N; i++){
		cin >> arr[i];
		breeds[arr[i]].push_back(i); //locations of a breed
	}
	for (int i = 1; i <=N; i++){
		if (breeds[i].size() == 0) continue;
		upd(breeds[i].front()); //first location of each breed
	}
	long long ans = 0;
	for (int i = 1; i <=N; i++){
		int b = arr[i];
		assert(breeds[b].front() == i);
		breeds[b].pop_front();
		int end = 0;
		if (breeds[b].size() == 0) end = N+1; 
		else end = breeds[b].front();
		//cout << i << ' ' << end << endl;
		ans = ans + (qry(end-1) - qry(i));
		if (end<=N) upd(end);
	}
	cout << ans << endl;
}