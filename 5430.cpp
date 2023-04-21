#include <bits/stdc++.h>
using namespace std;

int T, t, n, arrLength;
string numArray, p;
deque<int> AC, rAC, emptyAC;

void resetDeque() {
    AC.assign(emptyAC.begin(), emptyAC.end());
    rAC.assign(emptyAC.begin(), emptyAC.end());
}

void extractNum() {
    int len = numArray.length(), tmp = 0, cnt = 0;
    for (int i = 0; i < len; i++) {
        int num = numArray[i];
        if (num >= '0' && num <= '9') {
            if (tmp) {
                tmp *= 10;
                tmp += num-'0';
            }
            else
                tmp = num-'0';
            cnt++;
        }
        else
            if (cnt) {
                AC.push_back(tmp);
                rAC.push_front(tmp);
                tmp = 0;
                cnt = 0;
            }
    }
}

bool checkArray() {
    for (auto e : p) {
        arrLength = AC.size();
        if (e == 'R')
            AC.swap(rAC);
        else
            if (arrLength) {
                AC.pop_front();
                rAC.pop_back();
            }
            else {
                cout << "error";
                return false;
            }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> p >> n >> numArray;
        resetDeque();
        extractNum();
        if (checkArray()) {
            arrLength = AC.size();
            cout << '[';
            for (int i = 0; i < arrLength; i++) {
                cout << AC[i];
                if (i < arrLength-1)
                    cout << ',';
            }
            cout << ']';
        }
        cout << '\n';
    }
    return 0;
}