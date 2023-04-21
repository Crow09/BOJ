#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int sol[MAX];
int n, zero_min, zero_max, res = 0x7fffffff, value = -1;

void findZero(int l, int r) {
	if (l == r || l < 0 || r >= n || value == 0) return;
	value = sol[l]+sol[r];
	if (abs(value) < res) {
		zero_min = sol[l];
		zero_max = sol[r];
		res = abs(value);
	}
	if (value > 0)		findZero(l, r-1);
	else				findZero(l+1, r);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sol[i];
	}
	sort(sol, sol+n);
	findZero(0, n-1);
	cout << zero_min << ' ' << zero_max;
	return 0;
}
