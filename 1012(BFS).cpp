#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int arr[51][51];

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	arr[y][x] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int my = y+dy[i];
			int mx = x+dx[i];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (arr[my][mx] == 1) {
				arr[my][mx] = 0;
				q.push({my, mx});
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int r = 0; r < t; r++) {
		int res = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j]) {
					bfs(i, j);
					res++;
				}
		cout << res << endl;
	}
	return 0;
}
