/*
One of the farming chores Farmer John dislikes the most is hauling around lots of cow manure. In order to streamline this process, he comes up with an intriguing idea: instead of hauling manure between two points in a cart behind his tractor, why not shoot it through the air with a giant manure slingshot? (indeed, what could possibly go wrong...)
Farmer John's farm is built along a single long straight road, so any location on his farm can be described simply using its position along this road (effectively a point on the number line). FJ builds N slingshots (1≤N≤105), where the ith slingshot is described by three integers xi, yi, and ti, specifying that this slingshot can shoot manure from position xi to position yi in only ti total units of time.

FJ has M piles of manure to transport (1≤M≤105). The jth such pile needs to be moved from position aj to position bj. Hauling manure with the tractor for a distance of d takes d units of time. FJ is hoping to reduce this by allowing up to one use of any slingshot for transporting each pile of manure. Time FJ spends moving his tractor without manure in it does not count.

For each of the M manure piles, please help FJ determine the minimum possible transportation time, given that FJ can use up to one slingshot during the process.

INPUT FORMAT (file slingshot.in):
The first line of input contains N and M. The next N lines each describe a single slingshot in terms of integers xi, yi, and ti (0≤xi,yi,ti≤109). The final M lines describe piles of manure that need to be moved, in terms of integers aj and bj.
OUTPUT FORMAT (file slingshot.out):
Print M lines of output, one for each manure pile, indicating the minimum time needed to transport it.
SAMPLE INPUT:
2 3
0 10 1
13 8 2
1 12
5 2
20 7
SAMPLE OUTPUT:
4
3
10
Here, the first pile of manure needs to move from position 1 to position 12. Without using an slingshot, this would take 11 units of time. However, using the first slingshot, it takes 1 unit of time to move to position 0 (the slingshot source), 1 unit of time to fling the manure through the air to land at position 10 (the slingshot destination), and then 2 units of time to move the manure to position 12. The second pile of manure is best moved without any slingshot, and the third pile of manure should be moved using the second slingshot.

Problem credits: Brian Dean
*/
#include <bits/stdc++.h>
#define pii pair<int, int> 
#define piii pair<pair<int, int>, int>
#define f first
#define s second
using namespace std;
const int MXN = 1e5+10; //actually number of y values
const int MXM = 1e5+10;
int N, M, Y;
piii slings[MXN];
piii q[MXM];
set<int> yval;
map<int, int> comp; //compress y values
long st1[4*(MXN+MXM)], st2[4*(MXN+MXM)], st3[4*(MXN+MXM)], st4[4*(MXN+MXM)];
int ans[MXM];
const long INF = 3e9+10; 

void upd(long* st, int a, long val, int k=1, int l=0, int r=Y-1){
	assert(a >= 0 && a < Y);
	assert(val <= INF && val >= -1*INF);
	if (a > r || a < l) return;
	if (l == a && r == a) {
		st[k] = val;
		return;
	}
	int mid = (l+r)/2;
	upd(st,  a, val, k<<1, l, mid);
	upd(st, a, val, (k<<1)+1, mid+1, r);
	st[k] = min(st[k<<1], st[(k<<1)+1]);

}

long qry(long* st, int a, int b, int k=1, int l=0, int r=Y-1){ //get min of range
	//cout << k << ' ' << st[k] << ' ' << l << ' ' << r << endl;
	assert(b < Y); assert(a>=0);
	if (a > b){
		return INF;
	}
	if (r < a || l > b) return INF;
	if (r<=b && l>=a) return st[k];
	assert(l!=r);
	int mid = (l+r)/2;
	return min(qry(st, a, b, (k<<1), l, mid), qry(st, a, b, (k<<1)+1, mid+1, r));
}


int main(){
	ifstream cin("slingshot.in"); ofstream cout("slingshot.out");
	cin >> N >> M;
	for (int i= 0; i < N; i++){
		cin >> slings[i].f.f >> slings[i].f.s >> slings[i].s;
		yval.insert(slings[i].f.s);
	}
	for (int i= 0; i < M; i++){
		cin >> q[i].f.f >> q[i].f.s;
		q[i].s = i;
		yval.insert(q[i].f.s);
	}
	sort(slings, slings +N);
	sort(q, q+M);
	for (int x : yval){
		comp[x] = comp.size();
	}
	Y = comp.size(); // number of y values 
	assert(Y <=N+M);
	for (int i = 0; i < 4*(MXN+MXM); i++){
		st1[i] = INF; st2[i] = INF; st3[i] = INF; st4[i] = INF;
	}
	for (int i = 0; i < N; i++){//insert all into st 3 and 4
		int a = comp[slings[i].f.s];
 		upd(st3, a,(long)slings[i].s + slings[i].f.f - slings[i].f.s );
 		upd(st4, a,(long)slings[i].s + slings[i].f.f + slings[i].f.s );
	}
	int j = 0; //leftmost sling in st 3 and 4

	for (int i = 0; i < M; i++){
		int x = q[i].f.f; int y = q[i].f.s;

		//update the segtrees
		while (slings[j].f.f < x && j < N){
			int a = comp[slings[j].f.s];
			upd(st1, a, (long)slings[j].s -slings[j].f.f - slings[j].f.s );
			upd(st2, a, (long)slings[j].s -slings[j].f.f + slings[j].f.s );
			upd(st3, a, INF);
			upd(st4, a, INF);
			j++;
		}

		//4 quadrant queries
		//cout << qry(st1, 0, comp[y]) << ' ' << qry(st2, comp[y]+1, Y-1) << ' ' << qry(st3, 0, comp[y]) << ' ' << qry(st4, comp[y]+1, Y-1) << endl;
		long cost = abs(y-x);
		cost = min(cost, qry(st1, 0, comp[y])+x+y);
		cost = min(cost, qry(st2, comp[y]+1, Y-1)+x-y);
		cost = min(cost, qry(st3, 0, comp[y])-x+y);
		cost = min(cost, qry(st4, comp[y]+1, Y-1)-x-y);
		ans[q[i].s] = cost;
	}
	for(int i = 0; i < M; i++){
		cout << ans[i] << endl;
	}
}