#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX];

int tile(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (dp[x]) return dp[x];
	return dp[x] = (tile(x-1)+2*tile(x-2))%10007;
}

int main() {
	int n;
	cin >> n;
	cout << tile(n);
	return 0;
}
