#include <bits/stdc++.h>
using namespace std;

long long int dp[91];

long long int fibo(int x) {
	if (dp[x]) 		return dp[x];
	else if (x < 3) return 1;
	else 			return dp[x] = fibo(x-1)+fibo(x-2);
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}
