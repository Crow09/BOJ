#include <bits/stdc++.h>
using namespace std;

int n, m;
int maze[201][201];

int dirc_x[] = {-1, 1, 0, 0}; // x 방향 설정  
int dirc_y[] = {0, 0, -1, 1}; // y 방향 설정 

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	// queue를 이용하여 bfs 구현 
	q.push({x, y}); // queue에 현재 x, y(위치) 저장 
	while (!q.empty()) { // queue가 빌 때까지  
		int x = q.front().first; // x에 저장된 x(위치) 대입 
		int y = q.front().second; // y에 저장된 y(위치) 대입 
		q.pop(); // 후에 queue의 가장 위에 값 삭제 
		for (int i = 0; i < 4; i++) { // x, y의 네가지 방향 다 둘러 봄 
			int mx = x+dirc_x[i];
			int my = y+dirc_y[i];
			if (mx < 0|| mx >= n || my < 0 || my >= m) continue; // 주어진 미로의 밖으로 나갈 시 무시함 
			if (maze[mx][my] == 0) continue; // 벽인 경우 무시함 
			if (maze[mx][my] == 1) { // 벽이 아닐 시 
				maze[mx][my] = maze[x][y]+1; // 이동한 네 가지 위치 모두 이전 위치의 값과 더함(누적) 
				q.push({mx, my}); // 이동한 위치 queue에 추가 
			}
		}
	}
	return maze[n-1][m-1]; // 도착지에 최종적으로 들어있는 값 return 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &maze[i][j]);
	cout << bfs(0, 0);
	return 0;	
}
