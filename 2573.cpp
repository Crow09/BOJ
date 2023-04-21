#include <bits/stdc++.h>
#define MAX 300
#define Y first
#define X second
using namespace std;

int N, M, cnt, year;
int ocean[MAX][MAX];
bool vis[MAX][MAX];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool outOfBound(int y, int x) {
    return y < 0 || y >= N || x < 0 || x >= M;
}

void BFS(int y, int x, bool check = false) {
    queue<pair<int,int>> melting;
    melting.push({y, x});
    vis[y][x] = true;
    while (!melting.empty()) {
        pair<int,int> cur = melting.front(); melting.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if (outOfBound(ny, nx)) continue;
			if (vis[ny][nx]) continue;
			if (!check) {
	            if (ocean[ny][nx] == 0 && ocean[cur.Y][cur.X] > 0) ocean[cur.Y][cur.X]--;
	            if (ocean[ny][nx]) {
	            	vis[ny][nx] = true;
	            	melting.push({ny, nx});
				}
		    }
			else {
				if (ocean[ny][nx]) melting.push({ny, nx});
				vis[ny][nx] = true;
			}
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ocean[i][j];
    while (cnt < 2) {
    	cnt = 0;
    	year++;
    	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, false);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!vis[i][j] && ocean[i][j])
                    BFS(i, j);
        for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, false);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!vis[i][j] && ocean[i][j]) {
                    BFS(i, j, true);
                    cnt++;
                }
        if (cnt == 0) { year = 0; break; }
    }
    cout << year << '\n';
    return 0;
}