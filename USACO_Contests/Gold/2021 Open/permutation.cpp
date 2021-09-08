#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second
const int MXN = 40;
int N;
vector<pii> p;
int orientation(pii p, pii q, pii r)
{
	int val = (q.s - p.s) * (r.f - q.f) - (q.f - p.f) * (r.s - q.s);
	return (val > 0)? 1 : 2; // clock or counterclock wise
}
bool doIntersect(pair<pii, pii> e1, pair<pii, pii> e2){
	pii p1 = e1.f; pii q1 = e1.s;
	pii p2 = e2.f; pii q2 = e2.s;
	if (p1 == q2 || p1 == p2 || q1 == q2 || q1 == p2) return false;
	int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    return false;
}

bool intersect(vector<pair<pii, pii>>& edges, pii p1, pii p2){
	for (pair<pii, pii> edge : edges){
		if (doIntersect(edge, make_pair(p1, p2))){
			//cout << edge.f.f << ' ' << edge.f.s << ' ' << edge.s.f << ' ' << edge.s.s << ' ' << p1.f << ' ' << p1.s <<' ' << p2.f << ' ' << p2.s << endl;  
			return true;
		}
	}
	return false;
}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		int a, b; cin >> a >> b;
		p.push_back(make_pair(a, b));
	}
	sort(p.begin(), p.end());
	int ans = 0;
	do
    {
    	vector<pair<pii, pii>> edges;
    	edges.push_back(make_pair(p[0], p[1]));
    	edges.push_back(make_pair(p[1], p[2]));
    	edges.push_back(make_pair(p[0], p[2]));
    	bool works = true;
    	for (int i = 3; i < N; i++){
    		int c = 0; 
    		for (int j = 0; j < i; j++){
    			if (!intersect(edges, p[j], p[i])){
    				edges.push_back(make_pair(p[j], p[i]));
    				c++;
    			}
    		}
    		if (c!=3) {
    			works = false;
    			break;
    		}
    	}
    	if (works) ans++;
    } 
    while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}