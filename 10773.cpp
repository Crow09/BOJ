#include <bits/stdc++.h>
using namespace std;

int K, n, res;
stack<int> integer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    while (K--) {
        cin >> n;
        if (n == 0) {
            if (!integer.empty())
                integer.pop();
        }
        else
            integer.push(n);
    }
    while (!integer.empty()) {
        res += integer.top();
        integer.pop();
    }
    cout << res << '\n';
    return 0;
}