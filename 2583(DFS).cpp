#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int n, m, k;

vector<int> res;

int dfs(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m || arr[y][x]) return 0;
	arr[y][x] = 1;
	
	return 1
			+dfs(y-1, x)
			+dfs(y+1, x)
			+dfs(y, x-1)
			+dfs(y, x+1);
}

void makeArray(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
			arr[i][j] = 1;
}

int main() {
	int ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		makeArray(x1, y1, x2, y2);
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!arr[i][j]) {
				/* printf("%d %d\n", i, j); */
				res.push_back(dfs(i, j));
				ans++;
			}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	*/
	cout << ans << '\n';
	sort(res.begin(), res.end());
	for (auto e : res)
			cout << e << ' ';
	return 0;
}
