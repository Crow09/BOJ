#include <bits/stdc++.h>
using namespace std;

int n, m;
int maze[201][201];

int dirc_x[] = {-1, 1, 0, 0}; // x ���� ����  
int dirc_y[] = {0, 0, -1, 1}; // y ���� ���� 

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	// queue�� �̿��Ͽ� bfs ���� 
	q.push({x, y}); // queue�� ���� x, y(��ġ) ���� 
	while (!q.empty()) { // queue�� �� ������  
		int x = q.front().first; // x�� ����� x(��ġ) ���� 
		int y = q.front().second; // y�� ����� y(��ġ) ���� 
		q.pop(); // �Ŀ� queue�� ���� ���� �� ���� 
		for (int i = 0; i < 4; i++) { // x, y�� �װ��� ���� �� �ѷ� �� 
			int mx = x+dirc_x[i];
			int my = y+dirc_y[i];
			if (mx < 0|| mx >= n || my < 0 || my >= m) continue; // �־��� �̷��� ������ ���� �� ������ 
			if (maze[mx][my] == 0) continue; // ���� ��� ������ 
			if (maze[mx][my] == 1) { // ���� �ƴ� �� 
				maze[mx][my] = maze[x][y]+1; // �̵��� �� ���� ��ġ ��� ���� ��ġ�� ���� ����(����) 
				q.push({mx, my}); // �̵��� ��ġ queue�� �߰� 
			}
		}
	}
	return maze[n-1][m-1]; // �������� ���������� ����ִ� �� return 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &maze[i][j]);
	cout << bfs(0, 0);
	return 0;	
}
