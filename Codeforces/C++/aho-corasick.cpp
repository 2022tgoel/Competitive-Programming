/*
DNA is a nucleic acid present in the bodies of living things. Each piece of DNA contains a number of genes, some of which are beneficial and increase the DNA's total health. Each gene has a health value, and the total health of a DNA is the sum of the health values of all the beneficial genes that occur as a substring in the DNA. We represent genes and DNA as non-empty strings of lowercase English alphabetic letters, and the same gene may appear multiple times as a susbtring of a DNA.

Given the following:

An array of beneficial gene strings, . Note that these gene sequences are not guaranteed to be distinct.
An array of gene health values, , where each  is the health value for gene .
A set of  DNA strands where the definition of each strand has three components, , , and , where string  is a DNA for which genes  are healthy.
Find and print the respective total healths of the unhealthiest (minimum total health) and healthiest (maximum total health) strands of DNA as two space-separated values on a single line.

Input Format

The first line contains an integer, , denoting the total number of genes.
The second line contains  space-separated strings describing the respective values of  (i.e., the elements of ).
The third line contains  space-separated integers describing the respective values of  (i.e., the elements of ).
The fourth line contains an integer, , denoting the number of strands of DNA to process.
Each of the  subsequent lines describes a DNA strand in the form start end d, denoting that the healthy genes for DNA strand  are  and their respective correlated health values are .

Constraints

 the sum of the lengths of all genes and DNA strands 
It is guaranteed that each  consists of lowercase English alphabetic letters only (i.e., a to z).
Output Format

Print two space-separated integers describing the respective total health of the unhealthiest and the healthiest strands of DNA.

Sample Input 0

6
a b c aa d b
1 2 3 4 5 6
3
1 5 caaab
0 4 xyz
2 4 bcdybc
Sample Output 0

0 19
Explanation 0

In the diagrams below, the ranges of beneficial genes for a specific DNA on the left are highlighed in green and individual instances of beneficial genes on the right are bolded. The total healths of the  strands are:

Algorithm Implementation: https://www.toptal.com/algorithms/aho-corasick-algorithm

*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct TrieNode
{
	map<char, TrieNode*> children;
	TrieNode* suffixLink;
	TrieNode* dictLink;
	TrieNode* parent;
	char key; 
	vector<int> indeces;
	long long good = 0;
};

TrieNode* root = new TrieNode();
string genes[100000];
int good[100000];

void insert(string s, int good, int ind) {
	TrieNode* cur = root;
	for (char c : s){
		if (cur->children.count(c) == 0) {
			cur->children[c] = new TrieNode();
			cur->children[c]->parent = cur;
			cur->children[c]->key = c;
		}
		cur = cur->children[c];
	}
	cur->good += good;
	cur->indeces.push_back(ind);
}//get first links -> actual Trie links O(sum of all lengths of words)

TrieNode* calc_suffix(TrieNode* node){
	//calculates greatest proper suffix that is a prefix
	if (node == root || node->parent == root){
		return root;
	}
	TrieNode* link = node->parent->suffixLink;
	char c = node->key;
	while (link->children.count(c)==0 && link!=root){ //keep going down suffix links
		link = link->suffixLink;
	}
	if (link->children.count(c) == 0) return root;
	else return link->children[c];
}

TrieNode* calc_dict(TrieNode* node){//largest valid word that is a suffix
	if (node == root || node->parent == root){
		return root; 
	}
	if (node->suffixLink->good > 0) return node->suffixLink;// the largest suffix is a word
	else return node->suffixLink->dictLink;
}

void build(){
	//do after entire Trie is built
	//calculates suffix and dictionary links
	queue<TrieNode*> q;
	q.push(root);
	while(!q.empty()){
		TrieNode* cur = q.front();
		q.pop();
		cur->suffixLink = calc_suffix(cur);
		cur->dictLink = calc_dict(cur);
		for (pair<char, TrieNode*> child : cur->children){
			q.push(child.second);
		}
	}
}

long long qry(string s, int l, int r){
	long long ans = 0;
	TrieNode* cur = root;
	for(char c : s){
		if (cur->children.count(c) > 0){
			cur = cur->children[c];
		}
		else {
			TrieNode* link = cur->suffixLink;
			while (link!= root && link->children.count(c) == 0) {link = link->suffixLink;}
			if (link->children.count(c) == 0) { cur = link;}
			else cur = link->children[c];
		}
		//cout << (cur->key) << endl;
		ans+=cur->good;
		if (cur->good < 0) cout << "bad";
		for (int i : cur->indeces){
			if (i < l || i > r) ans-=good[i];
		}
		//go through all the dictLinks
		TrieNode* word = cur->dictLink;
		while (word!=root){
			ans+=word->good;
			for (int i : word->indeces){
				if (i < l || i > r) ans-=good[i];
			}
			word = word->dictLink;
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	for (int i =0; i < n; i++){
		cin >> genes[i];
	}
	for (int i = 0; i < n; i++){
		cin >> good[i];
	}
	for (int i = 0; i < n; i++){
		insert(genes[i], good[i], i);
	}
	build();
	
	int q;
	cin >> q;
	long long mi = LLONG_MAX;
	long long ma = 0;
	for(int i = 0; i < q; i++){
		int start, end;
		string word;
		cin >> start >> end >> word;
		long long result = qry(word, start, end);
		mi = min(result, mi);
		ma = max(result, ma);
	}
	cout << mi << ' ' << ma << endl;
}
