#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_N 8
#define BLANK 0
#define WALL 1
#define VIRUS 2

using namespace std;

int N, M;
int lab[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int answer = 0;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs() {
    int cur_lab[MAX_N][MAX_N];
    memcpy(cur_lab, lab, sizeof(lab)); // copy current lab
    queue<pair<int, int>> q; // queue for BFS
    // add all initial viruses to the queue
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cur_lab[i][j] == VIRUS) {
                q.push(make_pair(i, j));
            }
        }
    }
    // BFS starts
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // check out of bounds
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }
            // check if next cell is empty and not visited yet
            if (cur_lab[ny][nx] == BLANK && !visited[ny][nx]) {
                visited[ny][nx] = true;
                cur_lab[ny][nx] = VIRUS;
                q.push(make_pair(ny, nx));
            }
        }
    }
    // count the number of blank cells
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cur_lab[i][j] == BLANK) {
                cnt++;
            }
        }
    }
    answer = max(answer, cnt);
}

void build_wall(int cnt) {
    // build 3 walls
    if (cnt == 3) {
        bfs();
        return;
    }
    // try building a wall
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == BLANK) {
                lab[i][j] = WALL;
                build_wall(cnt + 1);
                lab[i][j] = BLANK;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    // read the input and build the initial lab
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
        }
    }
    // try building 3 walls
    build_wall(0);
    // print the answer
    cout << answer << endl;
    return 0;
}

