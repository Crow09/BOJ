#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;

int F, S, G, U, D;
int building[MAX], dist[MAX];
bool vis[MAX];

int dz[2];

void BFS() {
    queue<int> elevator;
    elevator.push(S);
    vis[S] = true;
    while (!elevator.empty()) {
        int cur = elevator.front(); elevator.pop();
        for (int dir = 0; dir < 2; dir++) {
            int move = cur + dz[dir];
            if (move > F || move < 1) continue;
            if (vis[move]) continue;
            dist[move] = dist[cur] + 1;
            vis[move] = true;
            elevator.push(move);
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    // F = 전체 층, S = 시작, G = 스타트링크 위치, U = 위, D = 아래
    dz[0] = U;
    dz[1] = -D;
    if (S == G) cout << "0\n";
    else {
        BFS();
        if (dist[G] == 0) cout << "use the stairs\n";
        else              cout << dist[G] << '\n';
    }
    return 0;
}