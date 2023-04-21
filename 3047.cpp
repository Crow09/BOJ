#include <bits/stdc++.h>
using namespace std;

int a[3001], ac[3001][2];

int main() {
	int n, m, MAX = -1, MIN = 9999;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ac[i][0] = a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (k < i) {
					ac[k][1] = (m-ac[k][0])%m;
					ac[k][0] = 0;
					continue;
				}
				int cnt = 0;
				while (ac[k][0] != j) {
					ac[k][0]++;
					cnt++;
					if (ac[k][0] == m) ac[k][0] = 0;
				}
				ac[k][1] = cnt;
			}
			cout << "RES : ";
			for (int k = 0; k < n; k++) {
				if (ac[k][1] > MAX) MAX = ac[k][1];
				cout << ac[k][1] << ' ';
			}
			cout << endl;
			if (MIN > MAX) MIN = MAX;
			MAX = -1;
			//cout << MIN << endl;
			//cout << "SORT : ";
			for (int k = 0; k < n; k++) {
				//cout << ac[k][0] << ' ';
				ac[k][0] = a[k];
				ac[k][1] = 0;
			}
			//cout << endl;
		}
	}
	cout << MIN;
	return 0;
}
/*
10 10
0 8 6 5 1 3 6 7 0 2
3 5 2 0 7 6 3 1 = 3 > 7
7 9 1 6 4 1 0 7 5 = 7 > 7
*/
