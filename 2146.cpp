#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int N, islandNum, ans = 987654321;
int island[101][101], dis[101][101];
bool vis[101][101];
queue<pair<int,int>> bridge;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool OOB(int ny, int nx) { return ny < 0 || ny >= N || nx < 0 || nx >= N; }

void isIsland(int y, int x) {
    vis[y][x] = true;
    island[y][x] = islandNum;
    while (!bridge.empty()) {
        pair<int,int> cur = bridge.front(); bridge.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if (island[ny][nx] == 0 || vis[ny][nx] || OOB(ny, nx)) continue;
            island[ny][nx] = islandNum;
            vis[ny][nx] = true;
            bridge.push({ny, nx});
        }
    }
    bridge = queue<pair<int,int>>();
}

void BFS() {
    while (!bridge.empty()) {
        pair<int,int> cur = bridge.front(); bridge.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if (island[ny][nx] == island[cur.Y][cur.X] || OOB(ny, nx)) continue;
            if (island[ny][nx]) ans = min(ans, dis[cur.Y][cur.X] + dis[ny][nx]);
            else {
                island[ny][nx] = island[cur.Y][cur.X];
                dis[ny][nx] = dis[cur.Y][cur.X] + 1;
                bridge.push({ny, nx});
            }
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> island[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)  {
            if (!vis[i][j] && island[i][j]) {
                islandNum++;
                bridge.push({i, j});
                isIsland(i, j);
            }
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (island[i][j])
                bridge.push({i, j});
    BFS();
    cout << ans << '\n';
    return 0;
}