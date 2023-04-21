#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX];

int tile(int x) {
	if (dp[x]) 		return dp[x];
	else if (x < 3) return x;
	else 			return dp[x] = (tile(x-1)+tile(x-2))%10007;
}

int main() {
	int n;
	cin >> n;
	cout << tile(n);
	return 0;
}
