/*
Your task is to efficiently calculate values abc modulo 109+7.

Input

The first input line has an integer n: the number of calculations.

Afther this, there are n lines, each containing three integers a, b and c.

Output

Print each value abc modulo 109+7.

Constraints
1≤n≤105
0≤a,b,c≤109
Example

Input:
3
3 7 1
15 2 2
3 4 5

Output:
2187
50625
763327764
*/
#include <iostream>
#define MOD 1000000007
using namespace std;

int N;
int numdiv;

int power(int a, int b, int mod){
	if (b==0) return 1;
	int ans = power(a, b>>1, mod);
	ans = (long long)ans*ans % mod;
	if (b&1) ans = (long long)ans*a%mod;
	return ans;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b, c;
		cin >> a >>b >> c;
		cout << power(a, power(b, c, MOD-1), MOD) << "\n";
	}
}