#include <bits/stdc++.h>
using namespace std;

int dp[12] = {1, 1, 2};

int f(int x) {
	if (dp[x])
		return dp[x];
	else
		return dp[x] = f(x-1)+f(x-2)+f(x-3);
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << f(n) << endl;
	}
	return 0;
}
