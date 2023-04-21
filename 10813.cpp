#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        arr[i] = i;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    for (int i = 1; i <= N; i++)
        cout << arr[i] << ' ';
    return 0;
}