#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int bigger;
int dist[MAX];
int vis[MAX];

int BFS(int N, int K) {
    vis[N] = 1; dist[N] = 0;
    queue<int> lookup;
    lookup.push(N);
    while (!lookup.empty()) {
        int cur = lookup.front(); lookup.pop();
        int moveDis;
        for (int dir = 0; dir < 3; dir++) {
            if (dir == 0)       moveDis = 1;
            else if (dir == 1)  moveDis = -1;
            else                moveDis = cur;
            int nx = cur + moveDis;
            if (nx < 0 || bigger + 1 < nx) continue;
            if (vis[nx] >= 3) continue;
            vis[nx]++;
            if (moveDis == cur) dist[nx] = min(dist[cur], dist[nx]);
            else                dist[nx] = min(dist[cur] + 1, dist[nx]);
            if (vis[nx] >= 3 && nx == K) return dist[nx];
            lookup.push(nx);
        }
    }
    return 0;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    bigger = max(N, K);
    fill(dist, dist + bigger + 1, MAX);
    cout << BFS(N, K) << '\n';
    return 0;
}