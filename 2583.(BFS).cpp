#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int n, m, k;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<int> result;

void makeArray(int x1, int y1, int x2, int y2) {
	for (int y = y1; y < y2; y++)
		for (int x = x1; x < x2; x++)
			arr[y][x] = 1;
}

int bfs(int y, int x) {
	int area = 1;
	queue<pair<int, int>> q;
	q.push({y, x});
	arr[y][x] = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i]+y;
			int nx = dx[i]+x;
			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			if (!arr[ny][nx]) {
				arr[ny][nx] = 1;
				q.push({ny, nx});
				area++;
			}
		}
	}
	return area;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		makeArray(x1, y1, x2, y2);
	}
	int ans = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (!arr[y][x]) {
//				printf("%d %d\n", x, y);
				result.push_back(bfs(y, x));
				ans++;
			}
//	for (int y = 0; y < n; y++) {
//		for (int x = 0; x < m; x++)
//			printf("%d ", arr[y][x]);
//		cout << endl;
//	}
	cout << ans << endl;
	sort(result.begin(), result.end());
	for (auto e : result)
		cout << e << ' ';
	return 0;
}
