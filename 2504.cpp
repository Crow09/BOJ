#include <bits/stdc++.h>
using namespace std;

int value, len, tmp = 1;
stack<char> correct;
string ps;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ps;
    len = ps.length();
    for (int i = 0; i < len; i++)
        if (ps[i] == '(') {
            tmp *= 2;
            correct.push(ps[i]);
        }
        else if (ps[i] == '[') {
            tmp *= 3;
            correct.push(ps[i]);
        }
        else {
            if (correct.empty() || i == 0) { value = 0; break; }
            else if (ps[i] == ')')
                if (correct.top() == '(') { if (ps[i-1] == '(') value += tmp; correct.pop(); tmp /= 2; }
                else                      { value = 0; break; }
            else
                if (correct.top() == '[') { if (ps[i-1] == '[') value += tmp; correct.pop(); tmp /= 3; }
                else                      { value = 0; break; }
        }
    if (!correct.empty()) value = 0;
    cout << value << '\n';
    return 0;
}