#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

int N, K;
int hideAndSeek[MAX], prePos[MAX];

int BFS() {
    if (N == K) return 0;
    queue<int> lookUp;
    lookUp.push(N);
    while (!lookUp.empty()) {
        int cur = lookUp.front(); lookUp.pop();
        for (int dis : {cur + 1, cur - 1, cur * 2}) {
            if (dis > 100000 || dis < 0 || hideAndSeek[dis]) continue;
            hideAndSeek[dis] = hideAndSeek[cur] + 1;
            prePos[dis] = cur;
            lookUp.push(dis);
            if (K == dis) return hideAndSeek[dis];
        }
    }
    return 0;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    cout << BFS() << '\n';
    stack<int> res;
	for (int cur = K; cur != N; cur = prePos[cur])
        res.push(cur);
    res.push(N);
    while (!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
    cout << '\n';
    return 0;
}