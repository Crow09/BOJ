#include <bits/stdc++.h>
using namespace std;

int N, h;
long long int cnt;
stack<int> building;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h;
        while (!building.empty()) {
            if (building.top() > h) {
                cnt += building.size();
                break;
            }
            else
                building.pop();
        }
        building.push(h);
    }
    cout << cnt << '\n';
    return 0;
}