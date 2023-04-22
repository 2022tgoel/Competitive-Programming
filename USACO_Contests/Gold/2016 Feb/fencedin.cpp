#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;
int A, B; 
int N, M;
int a[MAXN], b[MAXN];

int par[MAXN*MAXN];

int find(int x){
    if (par[x]>=0){
        int p = find(par[x]);
        par[x] = p;
        return p;
    } 
    else return x;
}

int find(int x, int y){
   // if (x+ y*(N+1) == 2) cout << 2 << ' ' << find(2) <<' ' << find(3) << endl;
    return find(x+ y*(N+1));
}

void comb(int a, int b){
   // cout << a << ' ' << b << endl;
    int p1 = find(a);
    int p2 = find(b);
    if (par[p1] > par[p2]) swap(p1, p2);
    par[p1]+=par[p2];
    par[p2] = p1;
  //  cout << "combined" << endl;
}

void comb(int x1, int y1, int x2, int y2){
    int a = x1+y1*(N+1);
    int b = x2+y2*(N+1);
    return comb(a, b);
}

struct Index {
    int i;
    bool vert;
    public: 
    int gap(){
        return (vert ? a[i+1] - a[i] : b[i+1] - b[i]);
    }
};

int compare (Index m, Index n){
    return m.gap() < n.gap();
}

vector<Index> order; 

int main(){
    ifstream cin("fencedin.in");
    ofstream cout("fencedin.out");
    memset(par, -1, sizeof(int)*MAXN*MAXN);
    cin >> A >> B;
    cin >> N >> M;
    for (int i = 1; i <= N ;i++) cin >> a[i];
    a[N+1] = A;
    for (int i = 1; i <= M ;i++) cin >> b[i];
    b[M+1] = B;
    sort(a, a+N+1);
    sort(b, b+M+1);
    for (int i = 0; i <=N; i++) order.push_back(Index{i, true});
    for (int i = 0; i <=M;i ++) order.push_back(Index{i, false});
    sort(order.begin(), order.end(), compare);
    int ans = 0;
    int edges = 0; 
    int nodes = (N+1)*(M+1);
    for (Index ind : order){
        if (ind.vert){
            for (int y = 0; y < M; y++){
                if (find(ind.i, y) != find(ind.i, y+1)){
                    ans += ind.gap();
                    comb(ind.i, y, ind.i, y+1);
                    edges++;
                    if (edges == nodes -1) break;
                }
            }
        }
        else {
            for (int x = 0; x < N; x++){
                if (find(x, ind.i) != find(x+1, ind.i)){
                    ans += ind.gap();
                    comb(x, ind.i, x+1, ind.i);
                    edges++;
                    if (edges == nodes-1) break;
                }
            }
        }
    }
    cout << ans << endl;

}