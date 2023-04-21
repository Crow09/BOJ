#include <bits/stdc++.h>
#define MAX 31
using namespace std;

int R, L, C;
char building[MAX][MAX][MAX];
queue<tuple<int,int,int>> nextPos;

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

int BFS() {
    bool vis[MAX][MAX][MAX] = {};
    int dist[MAX][MAX][MAX] = {};
    int z = get<0>(nextPos.front());
    int y = get<1>(nextPos.front());
    int x = get<2>(nextPos.front());
    vis[z][y][x] = true;
    while (!nextPos.empty()) {
        int curZ, curY, curX;
        tie(curZ, curY, curX) = nextPos.front(); nextPos.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = curZ + dz[dir];
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (vis[nz][ny][nx] || building[nz][ny][nx] == '#') continue;
            vis[nz][ny][nx] = true;
            dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
            if (building[nz][ny][nx] == 'E') return dist[nz][ny][nx];
            nextPos.push({nz, ny, nx});
        }
    }
    return -1;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        for (int h = 0; h < L; h++)
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++) {
                cin >> building[h][i][j];
                if (building[h][i][j] == 'S') nextPos.push({h, i, j});
            }
        int ans = BFS();
        if (ans < 0) cout << "Trapped!\n";
        else         cout << "Escaped in " << ans << " minute(s).\n";
        nextPos = queue<tuple<int,int,int>>();
    }
    return 0;
}