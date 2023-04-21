#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    int N, M, a, b, c;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        for (int j = a; j <= b; j++)
            arr[j] = c;
    }
    for (int i = 1; i <= N; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}