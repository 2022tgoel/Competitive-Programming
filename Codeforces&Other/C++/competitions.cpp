/*
A. Unusual Competitions
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
A bracketed sequence is called correct (regular) if by inserting "+" and "1" you can get a well-formed mathematical expression from it. For example, sequences "(())()", "()" and "(()(()))" are correct, while ")(", "(()" and "(()))(" are not.

The teacher gave Dmitry's class a very strange task — she asked every student to come up with a sequence of arbitrary length, consisting only of opening and closing brackets. After that all the students took turns naming the sequences they had invented. When Dima's turn came, he suddenly realized that all his classmates got the correct bracketed sequence, and whether he got the correct bracketed sequence, he did not know.

Dima suspects now that he simply missed the word "correct" in the task statement, so now he wants to save the situation by modifying his sequence slightly. More precisely, he can the arbitrary number of times (possibly zero) perform the reorder operation.

The reorder operation consists of choosing an arbitrary consecutive subsegment (substring) of the sequence and then reordering all the characters in it in an arbitrary way. Such operation takes l nanoseconds, where l is the length of the subsegment being reordered. It's easy to see that reorder operation doesn't change the number of opening and closing brackets. For example for "))((" he can choose the substring ")(" and do reorder ")()(" (this operation will take 2 nanoseconds).

Since Dima will soon have to answer, he wants to make his sequence correct as fast as possible. Help him to do this, or determine that it's impossible.

Input
The first line contains a single integer n (1≤n≤106) — the length of Dima's sequence.

The second line contains string of length n, consisting of characters "(" and ")" only.

Output
Print a single integer — the minimum number of nanoseconds to make the sequence correct or "-1" if it is impossible to do so.
*/

#include <bits/stdc++.h>
using namespace std;
int n;
string inp;
int main(){
	cin >> n >> inp;
	int pref = 0;
	int ans = 0;
	for (int i = 0; i < n;i++){\
		if (pref == -1 && inp[i] == '(') ans++;
		if (inp[i]  == '(') pref++;
		if (inp[i] == ')') pref--;
		if (pref < 0){
			ans++; //part of range
		}
	}
	if (pref !=0) cout << -1;
	else cout << ans;
}