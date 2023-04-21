#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, N, a, b;
    cin >> X >> N;
    while (N--) {
        cin >> a >> b;
        X -= a*b;
    }
    if (X) cout << "No\n";
    else   cout << "Yes\n";
    return 0;
}