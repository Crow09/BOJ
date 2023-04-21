#include <bits/stdc++.h>
using namespace std;

long long int t[1000001], ans = -10000000000, sum = 0;
int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> t[i];
		
	for (int i = 0; i < n; i++) {
		cnt++;
		sum += t[i];
		if (cnt >= k) {
			ans = max(ans, sum);
			sum -= t[i-k+1];
		}
	}
	cout << ans;
	return 0;
}
