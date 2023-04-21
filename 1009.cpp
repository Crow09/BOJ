#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) printf("1\n");
		else {
			b = b%4+4;
			int res = a;
			for (int j = 0; j < b-1; j++)
				res = res*a%10;
			if (res == 0) res = 10;
			printf("%d\n", res);
		}
	}
	return 0;
}
