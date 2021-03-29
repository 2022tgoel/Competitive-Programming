//solution - rolling hash to make building the string of sets O(n)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MXN = 510;
const int P = 31;
const int MOD = 1e9+7;
int N, M;
int cows[2*MXN][MXN];
int pows[MXN];

bool check(int a, int b) {
	set<int> strs;
	for (int i = 0; i < N; i++){
		strs.insert((cows[i][b] - cows[i][a-1]+MOD)%MOD);
	}
	bool works = true;
	for (int i = N; i < 2*N; i++){
		if (strs.count((cows[i][b] - cows[i][a-1]+MOD)%MOD)) {
			works = false; break;
		}
	}
	return works;
}

int main(){
	ifstream cin ("cownomics.in");
	ofstream cout ("cownomics.out");
	cin >> N >> M;
	pows[0] = 1;
	for (int i = 1; i < M; i++){
		pows[i] = ((ll)pows[i-1]*P)%MOD;
		//cout << pows[i] << endl;
	}
	map<char, int> mp;
	mp['A'] = 1; mp['G'] = 2; mp['T'] = 3, mp['C'] = 4;
	for (int i = 0; i < 2*N; i++){
		string s; cin >> s;
		for (int j = 1; j <= M; j++){
			cows[i][j]  = (cows[i][j-1] + ((ll)mp[s[j-1]]*pows[j-1]))%MOD;
		}
	}
	int a = 1; int b = 1; int best = M;
	while (b <=M){
		if (check(a, b)){
			best = min(best, b-a+1);
			a++; b = max(a, b);
		}
		else b++;
	}
	cout << best;
}