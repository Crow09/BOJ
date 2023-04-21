#include <bits/stdc++.h>
#define NOT_EMPTY !lookFor.empty()
using namespace std;

int N, K;
int hideAndSeek[200001];
queue<int> lookFor;

int BFS() {
    if (N == K) return 0;
    while (NOT_EMPTY) {
        int find = lookFor.front(); lookFor.pop();
        for (int dis : {find + 1, find - 1, find * 2}) {
            if (dis > 100000 || dis < 0 || hideAndSeek[dis]) continue;
            hideAndSeek[dis] = hideAndSeek[find] + 1;
            lookFor.push(dis);
            if (K == dis) return hideAndSeek[dis];
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    lookFor.push(N);
    cout << BFS() << '\n';
    return 0;
}