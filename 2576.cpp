
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, min = 0x7fffffff, sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n%2) {
			sum += n;
			if (min > n)
				min = n;
		}
	}
	if (sum == 0) cout << -1;
	else cout << sum << "\n" << min << "\n";
	return 0;
}
