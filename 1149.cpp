#include <bits/stdc++.h>
using namespace std;

int dp[1001][3];
int cost[3];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i-1][1], dp[i-1][2])+cost[0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2])+cost[1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1])+cost[2];
	}
	cout << min({dp[n][0], dp[n][1], dp[n][2]});
	return 0;
}
