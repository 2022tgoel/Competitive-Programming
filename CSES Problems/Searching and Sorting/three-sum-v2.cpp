//faster - gets AC
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int N, X;
pair<int, int> a[5000];
int main(){
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> a[i].f;
		a[i].s = i+1;
	}
	sort(a, a+N);
	for (int x = 0; x < N; x++){
		int y = 0; int z =N-1;
		while (y<z){
			if (a[x].f + a[y].f + a[z].f == X && y!=x && z!=x){
				cout << a[x].s << ' ' << a[y].s <<  ' ' <<  a[z].s << endl; return 0;
			}
			else if (a[x].f + a[y].f + a[z].f < X){
				y++;
			}
			else z--;
		}
	}
	cout << "IMPOSSIBLE";
}