/*
You are given a DNA sequence consisting of characters A, C, G, and T.

Your task is to find the shortest DNA sequence that is not a subsequence of the original sequence.

Input

The only input line contains a DNA sequence with n characters.

Output

Print the shortest DNA sequence that is not a subsequence of the original sequence. If there are several solutions, you may print any of them.

Constraints
1≤n≤106
Example

Input:
ACGTACGT

Output:
AAA
*/



#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int MXN = 1e6+1;
string s;
int arr[MXN];
int first[MXN][4];
int main(){
	map<char, int> ctoi; 
	ctoi['A'] = 0; ctoi['C'] = 1; ctoi['G'] = 2; ctoi['T'] = 3;
	map<int, char> itoc; 
	itoc[0] = 'A'; itoc[1] = 'C'; itoc[2] = 'G'; itoc[3] = 'T';
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		arr[i+1] = ctoi[s[i]];
	}
	for (int i = n-1; i>=0; i--){
		for (int j = 0; j <4; j++){
			first[i][j] = first[i+1][j];
			if (j == arr[i+1]) first[i][j]=i+1;
		}
	}
	string ans = "";
	int pos = 0;
	while (true){
		int best = 0;
		for (int i = 0; i < 4; i++){
			if ((first[pos][i] > first[pos][best] || first[pos][i] == 0) && first[pos][best]!=0) best = i;
		}
		ans +=itoc[best];
		pos = first[pos][best];
		if (pos == 0) break;
	}
	cout << ans;
}