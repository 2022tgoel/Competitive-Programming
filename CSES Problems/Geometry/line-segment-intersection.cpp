#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

int o(pii a, pii b, pii c){
	//1 --> ccw, 0 --> collinear, -1 --> cw
	long long x = ((long long)b.f-a.f)*(c.s-b.s) - ((long long)b.s-a.s)*(c.f-b.f);
	if (x > 0) return 1;
	else if (x==0) return 0;
	else return -1;
}

bool onSeg(pii a, pii b, pii c){
	return c.f <= max(b.f, a.f) && c.f >= min(b.f, a.f) && c.s <= max(a.s, b.s) && c.s >= min(a.s, b.s);
}

int main(){
	int t; cin >> t;
	for (int i= 0 ; i < t; i++){
		pii a1, a2, b1, b2; cin >> a1.f >> a1.s >> a2.f >> a2.s >> b1.f >> b1.s >> b2.f >> b2.s;
		int o1 = o(a1, a2, b1);
		int o2 = o(a1, a2, b2);
		int o3 = o(b1, b2, a1);
		int o4 = o(b1, b2, a2);
		if (o1!=o2 && o3!=o4) cout << "YES" << endl;
		else if (o1==0 && onSeg(a1, a2, b1)) cout << "YES" << endl;
		else if (o2==0 && onSeg(a1, a2, b2) ) cout << "YES" << endl;
		else if (o3 ==0 && onSeg(b1, b2, a1)) cout << "YES" << endl;
		else if (o4==0 && onSeg(b1, b2, a2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}
