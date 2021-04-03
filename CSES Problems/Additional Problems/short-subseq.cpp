/*
 * You are given a DNA sequence consisting of characters A, C, G, and T.

Your task is to find the shortest DNA sequence that is not a subsequence of the original sequence.

Input

The only input line contains a DNA sequence with n characters.

Output

Print the shortest DNA sequence that is not a contiguous subsequence of the original sequence. If there are several solutions, you may print any of them.

Constraints
1≤n≤106
Example

Input:
ACGTACGT

Output:
AA
  */

#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e6;
int ss[MXN];
set<long> seqs;

void gen_seqs(int seq, int l, int d){ 
	if (l==d){
		seqs.insert(seq);
	}
	else{
		for (int i = 0; i <=3; i++) gen_seqs(seq*4 + i, l+1, d);
	}
}

int main(){
	string s; cin >> s;
	int n = s.size();
	map<char, int> mp;
	mp['A'] = 0; mp['C'] = 1; mp['T'] = 2; mp['G'] =3;
	map<int, char> rev;
	rev[0] = 'A'; rev[1] = 'C'; rev[2] = 'T'; rev[3] = 'G'; 
	for (int i = 0; i < n; i++){
		ss[i] = mp[s[i]];
	}
	for (int i = 1; i<=10; i++){
		gen_seqs(0, 0, i);
		for (int j = 0; j < n-i+1; j++){
			int seq = 0;
			for (int k = j; k < j+i;k++){
				seq = 4*seq+ss[k];
			}
			seqs.erase(seq);
		}
		for (int sol : seqs){
			int x = sol;
			cout << x << endl;
			string ans = "";
			int m = 4;
			for (int j = 0; j < i; j++){
				ans = rev[x%m] + ans;
				x-=x%m;
				m*=4;
			}
			cout << "here" << ans; return 0;
		}
	}

}