#include <bits/stdc++.h>
#define pii pair<int, int>
#define s second
#define f first
#define mp make_pair
using namespace std;
int N, K;
long long M;
const int MXK = 2e5+10;
const int MXN = 1e5+1;
pii swaps[MXK];
int cows[MXN], goes[MXN], ans[MXN];
vector<pair<int, int>> visits[MXN];
bool visited[MXN];

vector<int> nodes;
void dfs(int node){
	if (visited[node]) return;
	visited[node] = true;
	nodes.push_back(node);
	dfs(goes[node]);
}

int add_steps(unordered_map<int, int>& window, int c, int node){
	for (auto pos : visits[node]) {
		if (window[pos.f] == 0) c++;
		window[pos.f]++;	
	}
	return c;
}

int add_rem_steps(unordered_map<int, int>& window, int c, int node, int r){
	for (auto pos : visits[node]) {
		if (pos.s > r) break;
		if (window[pos.f] == 0) c++;
		window[pos.f]++;	
	}
	return c;
}


int rem_steps(unordered_map<int, int>& window, int c, int node){
	for (auto pos : visits[node]) {
		window[pos.f]--;
		if (window[pos.f] == 0) c--;
		//assert(window[pos.f] >=0);
	}	
	return c;
}

int rem_rem_steps(unordered_map<int, int>& window, int c, int node, int r){
	for (auto pos : visits[node]) {
		if (pos.s > r) break;
		window[pos.f]--;
		if (window[pos.f] == 0) c--;
		//assert(window[pos.f] >=0);
	}	
	return c;
}

void print_window(unordered_map<int, int>& window){
	for (auto p : window){
		cout << "position: " << p.f << " times: " << p.s << endl;
	}
}

int main(){
	cin >> N >> K >> M;
	for (int i = 0; i < K; i++) 
		cin >> swaps[i].f >> swaps[i].s;
	for (int i = 1; i <= N; i++){
		cows[i] = i;
		visits[i].push_back(mp(i, 0));
	}
	for (int i = 0; i < K; i++){
		int p1 = swaps[i].f; int p2 = swaps[i].s;
		swap(cows[p1], cows[p2]);
		visits[cows[p1]].push_back(mp(p1, i +1));
		visits[cows[p2]].push_back(mp(p2, i+1));
	}
	for (int i = 1; i <= N; i++){
		goes[cows[i]] = i;
	} 
	long long S = M/K; // number of complete steps
	int R = M%K;
	for (int i = 1; i <=N; i++){
		if (visited[i]) continue;
		nodes.clear();
		dfs(i);
		long long s = S; int r = R;
		int size = nodes.size(); // cycle size
		if (s >= size) {
			//visits everything the cycle visits
			s = size; r = 0;
		}

		unordered_map<int, int> window;
		int c = 0;

		for (int j = 0; j < s; j++){
			c = add_steps(window, c, nodes[j]);
		}
		c = add_rem_steps(window, c, nodes[s%size], r);
		//print_window(window);
		ans[i] = c;
		c = rem_rem_steps(window, c, nodes[s%size], r);

		for (int j = 1; j < size; j++){
			int node = nodes[j];
			c = rem_steps(window, c, nodes[j-1]);
			c = add_steps(window, c, nodes[(j+s-1)%size]);
			//cout << "before rem" << endl;
			//print_window(window);
			c = add_rem_steps(window, c, nodes[(j+s)%size], r);
			//print_window(window);
			ans[node] = c;
			c = rem_rem_steps(window, c, nodes[(j+s)%size], r);
		}
	}
	for (int i =1; i <=N; i++) cout << ans[i] << endl;
}