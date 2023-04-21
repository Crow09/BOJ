#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, Min = 1e6, Max = 2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n_divisor;
		cin >> n_divisor;
		if (Min > n_divisor) Min = n_divisor;
		if (Max < n_divisor) Max = n_divisor;
	}
	cout << Min*Max;
	return 0;
}
