#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int testCase, len;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        list<char> keyLoger;
        list<char>:: iterator cursor = keyLoger.end();
        cin >> str;
        for (auto e : str) {
            if (e == '<' ) {
                if (!keyLoger.empty() && cursor != keyLoger.begin())
                    cursor--;
            }
            else if (e == '>') {
                if (!keyLoger.empty() && cursor != keyLoger.end())
                    cursor++;
            }
            else if (e == '-') {
                if (!keyLoger.empty())
                    keyLoger.erase(cursor);
            }
            else
                keyLoger.insert(cursor, e);
        }
        for (cursor = keyLoger.begin(); cursor != keyLoger.end(); cursor++)
            cout << *cursor;
        cout << "\n";
    }
    return 0;
}