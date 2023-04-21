#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, f;
	cin >> n >> f;
	n -= n%100;
	for (int i = n; i <= n+100; i++)
		if (i%f == 0) {
			printf("%02d", i%100);
			break;
		}
	return 0;
}
