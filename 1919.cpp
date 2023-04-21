#include <bits/stdc++.h>
using namespace std;

string anergram1, anergram2;
int charCnt1[26], charCnt2[26], result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin >> anergram1 >> anergram2;
    for (auto e : anergram1)
        charCnt1[e-'a']++;
    for (auto e : anergram2)
        charCnt2[e-'a']++;
    for (int i = 0; i < 26; i++)
        result += abs(charCnt1[i]-charCnt2[i]);
    cout << result;
    return 0;
}