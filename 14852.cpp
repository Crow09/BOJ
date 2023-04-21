#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

long long int dp[MAX][2];

long long int tile(int x) {
	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		dp[i][1] = (dp[i-1][1]+dp[i-3][0])%1000000007;
		dp[i][0] = (3*dp[i-2][0]+2*dp[i-1][0]+2*dp[i][1])%1000000007;
	}
	return dp[x][0];
}

int main() {
	int n;
	cin >> n;
	cout << tile(n);
	return 0;
}
