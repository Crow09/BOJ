#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX];

int tile(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (dp[x]) return dp[x];
	int res = 3*tile(x-2);
	for (int i = 3; i <= x; i++)
		if (i%2 == 0)
			res += 2*tile(x-i);
	return dp[x] = res;
}

int main() {
	int n;
	cin >> n;
	cout << tile(n);
	return 0;
}
