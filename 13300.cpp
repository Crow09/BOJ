#include <bits/stdc++.h>
using namespace std;

int N, capacity, room[2][6], minRoom;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> capacity;
    for (int i = 0; i < N; i++) {
        int gender, clas;
        cin >> gender >> clas;
        minRoom += room[gender][clas-1]++ % capacity == 0;
    }
    cout << minRoom;
    return 0;
}