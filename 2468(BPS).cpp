#include <bits/stdc++.h>
using namespace std;

int arr[101][101], copy_arr[101][101];
int n, res = 0x80000000;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	arr[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (arr[nx][ny] == 0) continue;
			if (arr[nx][ny]) {
				arr[nx][ny] = 0;
				q.push({nx, ny});
			}
		}
	}
}

void f(int tmp) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = copy_arr[i][j];
			if (arr[i][j] <= tmp)
				arr[i][j] = 0;
		}
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j]) {
				bfs(i, j);
				ans++;
			}
	res = max(res, ans);
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
	cout << res;
	return 0;
}
