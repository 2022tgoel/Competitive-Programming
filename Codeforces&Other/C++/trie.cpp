// Sample code to perform I/O:
#include <iostream>
#include <map>
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
struct TrieNode
{
	map<char,TrieNode*> children;
	int weight;
};

TrieNode root;

void insert(string s, int weight){
	TrieNode *cur = &root;
	for (char c : s){
		if (cur->children.find(c)==cur->children.end()){ //appropriate node
			cur->children[c] = new TrieNode();
		}
		cur = cur->children[c];
	}
	cur->weight = weight;
}

int DFS(TrieNode *cur){
	int m = cur->weight;
	for (pair<char, TrieNode*> child : cur->children){
		m = max(m, DFS(child.second)); 
	}
	return m;
}

int search(string s){
	TrieNode *cur = &root;
	for (char c : s){
		if (cur->children.find(c)==cur->children.end()){ //appropriate node
			return -1;
		}
		cur = cur->children[c];
	}
	return DFS(cur);
}
int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		string s;
		int weight;
		cin >> s >> weight;
		insert(s, weight);
	}
	for (int i = 0; i < q; i++){
		string s;
		cin  >> s;
		cout << search(s) << endl;
	}
}
