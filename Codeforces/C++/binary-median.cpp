#include <bits/stdc++.h>

using namespace std;
int n, m;

#define ll long long

int num_rem(vector<ll>& rem, ll num){
	int low = 0;
	int high = n;
	while (low <high){
		int mid = (low +high)/2;
		if (rem[mid] >=num){
			high = mid;
		}
		else {
			low = mid+1;
		}
	}
	return low;
}

ll find_ans(vector<ll>& rem){
	ll low = 0;
	ll high = ((ll)1 << m)-1; // [low, high]
	ll q = ((ll)1 << m) - n;
	while (low < high){
		ll mid = (low+high)/2;
		//cout << low << ' ' << mid << ' ' << high << endl;
		int idx = num_rem(rem, mid);
		bool removed = (rem[idx] == mid);
		ll numL = mid+1-idx-removed;
		ll numR = q - numL;
		if (numL < numR){
			low = mid+1;
		}
		else {
			high = mid;
		}

	}
	return low;
}

string convert(ll x){
	string s = "";
	for (int i = 0; i < m; i++){
		if (((ll)1 << i) & x){
			s="1" + s;
		}
		else s="0" + s;
	}
	return s;
}

ll convll(string s){
	ll num = 0;
	int d = 0;
	for (int i = m-1; i >=0; i--){
		if (s[i] == '1'){
			num+=((ll)1<<d);
		}
		d++;
	}
	return num;
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n >> m;
		//1 << m numbers
		vector<ll> rem(n);
		for (int i = 0; i < n;i++){
			string s;
			cin >> s;
			rem[i] = convll(s);
			//cout << rem[i] << ' ';
		}
		sort(rem.begin(), rem.end());
		cout << convert(find_ans(rem)) << endl;
	}
}