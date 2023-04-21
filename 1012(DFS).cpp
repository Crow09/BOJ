#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int m, n, k;

void dfs(int y, int x) {
	if (y < 0 || y >= m || x < 0 || x >= n || arr[y][x] == 0) return;
	arr[y][x] = 0;
	dfs(y+1, x);
	dfs(y-1, x);
	dfs(y, x+1);
	dfs(y, x-1);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int res = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j]) {
					dfs(i, j);
					res++;
				}
		cout << res << endl;
	}
	return 0;
}
