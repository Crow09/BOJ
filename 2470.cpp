#include <bits/stdc++.h>
using namespace std;

int solutions[100003], test1, test2, res = 0x7FFFFFFF, n, value = -1;

void sol(int l, int r) {
	if (l == r || l < 0 || r >= n || value == 0) return ;
	value = solutions[l]+solutions[r];
	if (abs(value) < res) {
		test1 = solutions[l];
		test2 = solutions[r];
		res = abs(value);
	}
	if (value < 0)	sol(l+1, r);
	else			sol(l, r-1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &solutions[i]);
	}
	sort(solutions, solutions+n);
	sol(0, n-1);
	printf("%d %d", test1, test2);
	return 0;
}
