#include <bits/stdc++.h>
#define NOT_EMPTY !tomato.empty()
#define X get<0>(tomato.front())
#define Y get<1>(tomato.front())
#define Z get<2>(tomato.front())
using namespace std;

int M, N, H, ans;
int board[103][103][103];
int dist[103][103][103];
queue<tuple<int,int,int>> tomato;

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void BFS() {
    while (NOT_EMPTY) {
        tuple<int,int,int> cur = tomato.front(); tomato.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (dist[nx][ny][nz] > -1) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            tomato.push({nx, ny, nz});
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    for (int h = 0; h < H; h++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> board[i][j][h];
                if (board[i][j][h] == 1)
                    tomato.push({i, j, h});
                else if (board[i][j][h] == 0)
                    dist[i][j][h] = -1;
            }
    BFS();
    for (int h = 0; h < H; h++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (dist[i][j][h] == -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                else
                    ans = max(dist[i][j][h], ans);
    cout << ans << '\n';
    return 0;
}