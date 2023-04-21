#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int T, w, h;
char maze[1001][1001];
int dist1[1001][1001], dist2[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void fireBFS(queue<pair<int,int>> &fire) {
    bool vis[1001][1001] = {};
    while (!fire.empty()) {
        pair<int,int> cur = fire.front(); fire.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dist1[nx][ny] >= 0 || maze[nx][ny] == '#' || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            fire.push({nx, ny});
        }
    }
}

void sangGeunBFS(queue<pair<int,int>> &sangGeun) {
    bool vis[1001][1001] = {};
    while (!sangGeun.empty()) {
        pair<int,int> cur = sangGeun.front(); sangGeun.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)  { cout << dist2[cur.X][cur.Y] + 1; return; }
            if (maze[nx][ny] == '#') continue;
            if (dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 && dist1[nx][ny] != -1 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            sangGeun.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE"; return;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        queue<pair<int,int>> fire;
        queue<pair<int,int>> sangGeun;
        cin >> w >> h;
        for (int i = 0; i < h; i++) fill(dist1[i], dist1[i] + w, -1);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == '*') {
                    fire.push({i, j});
                    dist1[i][j] = 0;
                }
                else if (maze[i][j] == '@') {
                    sangGeun.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        fireBFS(fire);
        sangGeunBFS(sangGeun);
        cout << '\n';
    }
    return 0;
}