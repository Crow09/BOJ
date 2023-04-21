#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[101] = {}, sum = 0, t;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	t = sum;
	for (int i = 0; i < 9; i++) {
		sum = t;
		for (int j = 0; j < 9; j++) {
			if (i == j) continue;
			else 		sum -= a[i]+a[j];
			if (sum == 100) {
				a[i] = 0; a[j] = 0;
				sort(a, a+9);
				for (int i = 0; i < 9; i++)
					if (a[i])
						cout << a[i] << endl;
				return 0;
			}
			sum = t;
		}
	}
	return 0;
}
