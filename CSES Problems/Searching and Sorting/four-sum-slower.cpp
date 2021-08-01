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
using namespace std;
int N, X, A[1010];
unordered_map<int,pii> early;
unordered_map<int, pii> late; 
int main(){
	cin >> N >> X;
	for (int i = 0; i < N;i++){
		cin >> A[i];
	}
	for (int i = 0;i< N;i++){
		for (int j =i+1; j < N; j++){
			int sum = A[i] + A[j];
			if (early.count(sum) == 0) early[sum] = make_pair(j+1, i+1);
			else early[sum] = min(early[sum], make_pair(j+1, i+1));
			if (late.count(sum) == 0) late[sum] = make_pair(i+1, j+1);
			else late[sum] = max(late[sum], make_pair(i+1, j+1));
		}
	}
	for (auto p : early){
		int opp = X - p.f;
		if (late.count(opp)!=0 && late[opp].f> p.s.f){
			cout << p.s.f << ' ' << p.s.s << ' ' << late[opp].f << ' ' << late[opp].s << endl;return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}