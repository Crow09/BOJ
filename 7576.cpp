#include <bits/stdc++.h>
#define NOT_EMPTY !tomato.empty()
#define X first
#define Y second
using namespace std;

int M, N, ans, arr[1001][1001], dist[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int,int>> tomato;

void BFS() {
    while (NOT_EMPTY) {
        pair<int,int> cur = tomato.front(); tomato.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] > -1) continue; // 이미 방문하였거나, 토마토가 익어있거나, 토마토가 없음
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            tomato.push({nx, ny});
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                tomato.push({i, j}); // 토마토가 익었다면 dist에 아무 것도 추가 하지 않음
            else if (arr[i][j] == 0)
                dist[i][j] = -1; // 토마토가 익지 않았다면 dist에 심어져 있지 않다는 표시
        }
    BFS();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            else
                ans = max(dist[i][j], ans);
    }
    cout << ans << '\n';
    return 0;
}