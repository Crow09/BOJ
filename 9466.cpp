#include <bits/stdc++.h>
#define MAX 100001
#define NEXT graph[cur]
using namespace std;

int graph[MAX];
bool vis[MAX], done[MAX];
int cnt;

void DFS(int cur) {
    vis[cur] = true;
    if (!vis[NEXT]) DFS(NEXT); // 다음 학생이 아직 방문되지 않았다면, 해당 학생을 기준으로 다시 그래프 탐색
    else {
        if (!done[NEXT]) { // 현재 학생이 가리키는 학생은 아직 사이클에 들어갔는지 확인 할 수 없음
            for (int i = NEXT; i != cur; i = graph[i])
                cnt++; // 사이클 완성의 경우를 카운트
            cnt++; // 현재 학생(cur)까지 카운트
        }
    }
    done[cur] = true; // 현재 학생이 사이클이 도는지 확인이 끝남
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, n;
    cin >> T;
    while (T--) {
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> graph[i];
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                DFS(i);
        cout << n - cnt << '\n';
        fill(vis, vis + MAX, false);
        fill(done, done + MAX, false);
    }
    return 0;
}