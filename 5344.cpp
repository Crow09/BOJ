#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, testCase;
	cin >> testCase;
	while (testCase--) {
		cin >> a >> b;
		cout << __gcd(a, b) << '\n';
	}
	return 0;
}
