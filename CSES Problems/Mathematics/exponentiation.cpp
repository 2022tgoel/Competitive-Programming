/*
Your task is to efficiently calculate values ab modulo 109+7.

Input

The first input line contains an integer n: the number of calculations.

After this, there are n lines, each containing two integers a and b.

Output

Print each value ab modulo 10^9+7.

Constraints
1≤n≤2⋅10^5
0≤a,b≤10^9
Example

Input:
3
3 4
2 8
123 123

Output:
81
256
921450052
*/

#include <iostream>
#define MOD 1000000007
using namespace std;

int power(int a, int b){
	if (b==0) return 1;
	int ans = power(a, b>>1);
	ans = (long long)ans*ans%MOD;
	if (b&1) ans = (long long)ans*a%MOD;
	return ans;
}

int N;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >>b;
		cout << power(a, b) << "\n";
	}
}