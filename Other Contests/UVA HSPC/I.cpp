#include <bits/stdc++.h>
using namespace std;

const int MXK=5010;
map<string, set<string>> games[MXK];
int par[MXK];
map<string, int> pind;
int k, q;

int find(int a){
	if (par[a] == a) return a;
	int r = find(par[a]);
	par[a] = r;
	return r;
}

int un(int a, int b){
	int x = find(a);
	int y = find(b);
	par[y] = x;
	for (pair<string, set<string>> g: games[y]){
		games[x][g.first].insert(g.second.begin(), g.second.end());
	}
}

void addPerson(string s){
	if (pind[s]==0){
		pind[s] = pind.size();
		par[pind[s]] = pind[s];
	}
}

void addGame(string p, string game){
	games[find(pind[p])][game].insert(p);
}

set<string> qry(string p, string game){
	return games[find(pind[p])][game];
}

void printGames(){
	for (int i = 0; i < 3; i++){
		for (pair<string, set<string>> g: games[i]) cout <<  i << ' ' << g.first << endl;
	}
}

int main(){
	cin >> k;
	cin >> q;
	for (int i = 0; i < q; i++){
		string s1; cin >> s1;
		//cout << s1 << endl;
		if (s1 == "Can"){
			//query case
			string p, borrow, g; 
			cin >> p >> borrow >> g;
			addPerson(p);

			set<string> ppl = qry(p, g);
			if (ppl.size() == 0){
				cout << "No" << endl;
				continue;
			}
			cout << p << " can borrow from ";
			int x =0;
			for (string person : ppl){
				x++;
				cout << person;
				if (x!=ppl.size()) cout << ", ";
			}
			cout << endl;
			continue;

		}
		string s2; cin >> s2;
		if (s2 == "and"){
			//join case
			string p, are, f; cin >> p >> are >> f;
			addPerson(s1); addPerson(p);
			un(pind[s1], pind[p]);

		}
		if (s2 == "owns"){
			//add a game case
			string s3; cin >> s3;
			addPerson(s1);
			addGame(s1, s3);
		}
	}
}