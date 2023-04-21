#include <bits/stdc++.h>
using namespace std;

int dp[41] = {0, 1};
int cnt0, cnt1;

int fibo(int x) {
	if (dp[x])
		return dp[x];
	else if (x == 0) {
		cnt0++;
		return 0;
	}
	else if (x == 1) {
		cnt1++;
		return 1;
	}
	else
		dp[x] = fibo(x-1)+fibo(x-2);
}

int main() {
	int n, t;
	cin >> t;
	for (int i = 2; i <= 40; i++)
		dp[i] = dp[i-1]+dp[i-2];
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0) cout << "1 0\n";
		else {
			fibo(n);
			cout << dp[n-1] << ' ' << dp[n] << endl;
		}
	}
	return 0;
}
