#include <bits/stdc++.h>
using namespace std;

int overLap, res;
char ps[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ps;
    int len = strlen(ps);
    for (int i = 0; i < len; i++)
        if (ps[i] == '(')
            if (ps[i+1] == ')')
                res += overLap;
            else
                overLap++;
        else
            if (ps[i-1] != '(') {
                overLap--;
                res++;
            }
    cout << res << '\n';
    return 0;
}
