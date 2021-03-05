/*
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤1000
1≤x,ai≤109
Example

Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7
*/


#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int N, X, A[1010];
gp_hash_table<int,vector<pii>> sums({},{},{},{},{1<<16});
//unordered_map<int,vector<pii>> sums; 
int main(){
	cin >> N >> X;
	for (int i = 0; i < N;i++){
		cin >> A[i];
	}
	for (int i = 0;i< N;i++){
		for (int j =i+1; j < N; j++){
			int sum = A[i] + A[j];
			sums[sum].push_back(make_pair(i, j));

		}
	}
	for (int i = 0;i< N;i++){
		for (int j =i+1; j < N; j++){
			int sum = A[i] + A[j];
			int opp = X - sum;
			for (pii p : sums[opp]){ 

				if (p.f!=i && p.s!=i && p.f!=j && p.s!=j) {
					cout << i+1 << ' ' << j+1 << ' ' << p.f+1 << ' ' << p.s+1;
					exit(0);
				}
			}

		}
	}
	cout << "IMPOSSIBLE" << endl;
}