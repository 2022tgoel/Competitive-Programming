/*
D. Omkar and Circle
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Danny, the local Math Maniac, is fascinated by circles, Omkar's most recent creation. Help him solve this circle problem!

You are given n nonnegative integers a1,a2,…,an arranged in a circle, where n must be odd (ie. n−1 is divisible by 2). Formally, for all i such that 2≤i≤n, the elements ai−1 and ai are considered to be adjacent, and an and a1 are also considered to be adjacent. In one operation, you pick a number on the circle, replace it with the sum of the two elements adjacent to it, and then delete the two adjacent elements from the circle. This is repeated until only one number remains in the circle, which we call the circular value.

Help Danny find the maximum possible circular value after some sequences of operations.

Input
The first line contains one odd integer n (1≤n<2⋅105, n is odd)  — the initial size of the circle.

The second line contains n integers a1,a2,…,an (0≤ai≤109)  — the initial numbers in the circle.

Output
Output the maximum possible circular value after applying some sequence of operations to the given circle.
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+10;
int n, a[MXN];
long long pe[MXN], po[MXN]; // pe is sum of all even indeces to the right, po is sum of all odd indeces
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (i > 0){
			po[i] = po[i-1];
			pe[i] = pe[i-1];
		}
		if (i%2)po[i]+=a[i];
		else pe[i]+=a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		long long score = 0;
		if (i%2){
			score = pe[i-1] + po[n-1] - po[i-1];
		}
		else{
			if (i > 0) score+=po[i-1];
			score += pe[n-1] - pe[i-1];
		}
		ans = max(ans, score);
	}
	cout << ans;
}