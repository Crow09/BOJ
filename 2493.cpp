#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, height;
    stack<pair<int,int>> tower;
    cin >> N;
    for (int idx = 1; idx <= N; idx++) {
        cin >> height;
        while (!tower.empty()) {
            if (tower.top().first > height) {
                cout << tower.top().second << ' ';
                break; // If it's higher than "height", output the idx and break
            }
            tower.pop(); // else tower's pop the top elements
        }
        if (tower.empty()) cout << 0 << ' '; // output 0 when if haven't higher tower
        tower.push({height, idx}); // push the current tower and locate
    }
    return 0;
}