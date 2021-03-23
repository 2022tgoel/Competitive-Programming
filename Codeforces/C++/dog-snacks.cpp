/*
E. Dog Snacks
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
Gildong is playing with his dog, Badugi. They're at a park that has n intersections and n−1 bidirectional roads, each 1 meter in length and connecting two intersections with each other. The intersections are numbered from 1 to n, and for every a and b (1≤a,b≤n), it is possible to get to the b-th intersection from the a-th intersection using some set of roads.

Gildong has put one snack at every intersection of the park. Now Gildong will give Badugi a mission to eat all of the snacks. Badugi starts at the 1-st intersection, and he will move by the following rules:

Badugi looks for snacks that are as close to him as possible. Here, the distance is the length of the shortest path from Badugi's current location to the intersection with the snack. However, Badugi's sense of smell is limited to k meters, so he can only find snacks that are less than or equal to k meters away from himself. If he cannot find any such snack, he fails the mission.
Among all the snacks that Badugi can smell from his current location, he chooses a snack that minimizes the distance he needs to travel from his current intersection. If there are multiple such snacks, Badugi will choose one arbitrarily.
He repeats this process until he eats all n snacks. After that, he has to find the 1-st intersection again which also must be less than or equal to k meters away from the last snack he just ate. If he manages to find it, he completes the mission. Otherwise, he fails the mission.
Unfortunately, Gildong doesn't know the value of k. So, he wants you to find the minimum value of k that makes it possible for Badugi to complete his mission, if Badugi moves optimally.

Input
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤104).

The first line of each test case contains one integer n (2≤n≤2⋅105) — the number of intersections of the park.

The next n−1 lines contain two integers u and v (1≤u,v≤n, u≠v) each, which means there is a road between intersection u and v. All roads are bidirectional and distinct.

It is guaranteed that:

For each test case, for every a and b (1≤a,b≤n), it is possible to get to the b-th intersection from the a-th intersection.
The sum of n in all test cases doesn't exceed 2⋅105.
Output
For each test case, print one integer — the minimum possible value of k such that Badugi can complete the mission.
*/

#include <bits/stdc++.h>
using namespace std;
int calc (int cur, vector<vector<int>>& graph, vector<bool>& v, vector<int>& k){
	v[cur] = true;
	k[cur] = 0;
	multiset<int> paths;
	int numChild = 0;
	for (int child : graph[cur]){
		if (!v[child]){
			 int path = calc(child, graph, v, k)+1;
			 paths.insert(path);
			 k[cur] = max(k[cur], k[child]);
			 numChild++;
		}
	}
	if (paths.size() == 0) return 0; //leaf node
	if (cur == 0){
		//special case
		int mxp = *--paths.end();
		k[cur] = max(k[cur], mxp);
		if (paths.count(mxp) > 1){
			k[cur] = max(k[cur], mxp+1);
		}
		return 0;
	}
	else {
		int mxp = *--paths.end();
		int mnp = *paths.begin();
		k[cur] = max(k[cur], mxp + (numChild > 1 ? 1 : 0));
		return mnp;
	}
	

}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<vector<int>> graph(n);
		vector<bool> v(n);
		for (int i = 0; i < n; i++) v[i] = false;
		vector<int> k(n);
		for (int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		calc(0, graph, v, k);
		cout << k[0] << endl;
	}
}