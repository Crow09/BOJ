#include <bits/stdc++.h>
#define RED color == 'R'
#define GREEN color == 'G'
#define BLUE color == 'B'
using namespace std;

int N, cnt, amblyCnt;
char grid[101][101];
bool vis[101][101];

void DFS(int y, int x, char color) {
    if (y < 0 || y >= N || x < 0 || x >= N) return;
    if (vis[y][x]) return;
    if (RED && grid[y][x] != 'R' ||
        GREEN && grid[y][x] != 'G' ||
        BLUE && grid[y][x] != 'B') return;
    vis[y][x] = true;
    DFS(y + 1, x, color);
    DFS(y - 1, x, color);
    DFS(y, x + 1, color);
    DFS(y, x - 1, color);
}

void callDFS() {
    cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vis[i][j]) {
                DFS(i, j, grid[i][j]);
                cnt++;
            }
    cout << cnt << '\n';
}

void visReset() {
    for (int i = 0; i < N; i++)
        fill(vis[i], vis[i] + N, false);
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    callDFS(); // 일반인
    visReset();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'R') grid[i][j] = 'G';
    callDFS(); // 적록색약인
    return 0;
}