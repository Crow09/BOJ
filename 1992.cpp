#include <bits/stdc++.h>
using namespace std;

int arr[66][66];

void divide(int y, int x, int divSize) {
	if (divSize == 0) return;
	int isOne = 0, isZero = 0;
	
	for (int i = y; i < y+divSize; i++)
		for (int j = x; j < x+divSize; j++) {
			if (arr[i][j])  isOne++;
			else 			isZero++;
		}
	
	if (isOne && isZero) {
		cout << '(';
		divSize/=2;
		divide(y, x, divSize);
		divide(y, x+divSize, divSize);
		divide(y+divSize, x, divSize);
		divide(y+divSize, x+divSize, divSize);
		cout << ')';
	}
	else
		cout << (isOne > isZero ? 1 : 0);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &arr[i][j]);
			
	divide(1, 1, n);
	return 0;
}
