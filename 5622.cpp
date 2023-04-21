#include <bits/stdc++.h>
using namespace std;

int main() {
    int res = 0;
    string number;
    cin >> number;
    for (auto e : number) {
        if (e <= 'C')      res++;
        else if (e <= 'F') res += 2;
        else if (e <= 'I') res += 3;
        else if (e <= 'L') res += 4;
        else if (e <= 'O') res += 5;
        else if (e <= 'S') res += 6;
        else if (e <= 'V') res += 7;
        else if (e <= 'Z') res += 8;
        else               res += 9;
        res += 2;
    }
    cout << res << '\n';
    return 0;
}