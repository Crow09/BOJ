#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int R, C;
char maze[1001][1001];
int dist1[1001][1001], dist2[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int>> fire;
queue<pair<int,int>> jihun;

void fireBFS() {
    while (!fire.empty()) {
        pair<int,int> cur = fire.front(); fire.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (dist1[nx][ny] >= 0 || maze[nx][ny] == 'J' || maze[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            fire.push({nx, ny});
        }
    }
}

void jihunBFS() {
    while (!jihun.empty()) {
        pair<int,int> cur = jihun.front(); jihun.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)  { cout << dist2[cur.X][cur.Y] + 1; return; }
            if (dist2[nx][ny] > 0 || maze[nx][ny] == '#') continue;
            if (dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 && dist1[nx][ny] != -1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            jihun.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE"; return;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++) fill(dist1[i], dist1[i] + C, -1);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'F') {
                fire.push({i, j});
                dist1[i][j] = 0;
            }
            else if (maze[i][j] == 'J')
                jihun.push({i, j});
        }
    fireBFS();
    jihunBFS();
    cout << '\n';
    return 0;
}