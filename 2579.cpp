#include <bits/stdc++.h>
using namespace std;

int dp[301];
int score[301];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	dp[0] = score[0];
	dp[1] = max(score[0]+score[1], score[1]);
	dp[2] = max(score[0]+score[2], score[1]+score[2]);
	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i-2], score[i-1]+dp[i-3])+score[i];
	cout << dp[n-1];
	return 0;
}
