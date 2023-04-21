#include <bits/stdc++.h>
#define MAX 200
using namespace std;

int K, W, H;
int chess[MAX][MAX];

int dist[MAX][MAX];
int vis[MAX][MAX][2];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int knightDy[] = {2, 2, 1, 1, -1, -1, -2, -2};
int knightDx[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int BFS() {
    queue<tuple<int,int,int>> nextPos;
    nextPos.push({0, 0. 0});
    vis[0][0][0] = vis[0][0][1] = K;
    while (!nextPos.empty()) {
        int y, x, jump;
        tie(y, x, jump) = nextPos.front(); nextPos.pop();
        for (int dir = 0; dir < 4; dir++) {
            int dy = y + ny[dir];
            int dx = x + nx[dir];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> chess[i][j];
    cout << BFS() << '\n';
    return 0;
}