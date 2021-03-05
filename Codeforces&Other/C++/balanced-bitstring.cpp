/*
A. Balanced Bitstring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A bitstring is a string consisting only of the characters 0 and 1. A bitstring is called k-balanced if every substring of size k of this bitstring has an equal amount of 0 and 1 characters (k2 of each).

You are given an integer k and a string s which is composed only of characters 0, 1, and ?. You need to determine whether you can make a k-balanced bitstring by replacing every ? characters in s with either 0 or 1.

A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains two integers n and k (2≤k≤n≤3⋅105, k is even)  — the length of the string and the parameter for a balanced bitstring.

The next line contains the string s (|s|=n). It is given that s consists of only 0, 1, and ?.

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case, print YES if we can replace every ? in s with 0 or 1 such that the resulting bitstring is k-balanced, or NO if it is not possible.
*/

#include <bits/stdc++.h>
using namespace std;
const int MXN = 3e5+10;
int t;

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, k;
		cin >> n >> k;
		string inp;
		cin >> inp;
		vector<int> val(k); // val of i%k
		for (int i = 0; i < k; i++) val[i] = -1;
		bool fail = false;
		for (int i = 0; i < n; i++){
			int c = inp[i];
			if (c == '?') continue;
			if (c == '1') {
				if (val[i%k] == -1) val[i%k] = 1;
				if (val[i%k] == 0) fail = true;
			}
			else if (c == '0') {
				if (val[i%k] == -1) val[i%k] = 0;
				if (val[i%k] == 1) fail =true;
			}
		}
		if (fail) {
			cout << "NO" << endl;
			continue;
		}
		int c1 = 0;
		int c2 = 0;
		for (int i = 0; i < k; i++){
			if (val[i] == 1)c1++;
			if (val[i] == 0) c2++;
		}
		if (c1 > k/2 || c2 > k/2){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
}