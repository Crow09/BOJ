#include <bits/stdc++.h>
using namespace std;

int arr[101][101], copy_arr[101][101];
int n, ans = 0x80000000;

void dfs(int x, int y) {
	if (x >= n || y >= n || x < 0 || y < 0 || arr[x][y] == 0) return;
	arr[x][y] = 0;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}

void f(int tmp) {
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = copy_arr[i][j];
			if (arr[i][j] <= tmp)
				arr[i][j] = 0;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j]) {
				dfs(i, j);
				res++;
			}
	ans = max(ans, res);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			copy_arr[i][j] = arr[i][j];
		}
	for (int i = 0; i <= 100; i++)
		f(i);
	cout << ans;
	return 0;
}
