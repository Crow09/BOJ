#include <bits/stdc++.h>
#define MIN 0x80000000
#define X first
#define Y second
using namespace std;

int n, m, maxRes = MIN, cntRes, canvas[501][501];
bool vis[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int BFS(int x, int y) {
    int cnt = 1;
    queue<pair<int,int>> move;
    vis[x][y] = true;
    move.push({x, y});
    while (!move.empty()) {
        pair<int,int> cur = move.front(); move.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || canvas[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            move.push({nx, ny});
            cnt++;
        }
    }
    return cnt;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> canvas[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (canvas[i][j] == 1 && !vis[i][j]) {
                maxRes = max(BFS(i, j), maxRes);
                cntRes++;
            }
    if (maxRes == MIN) cout << "0\n0";
    else               cout << cntRes << '\n' << maxRes << '\n';
    return 0;
}