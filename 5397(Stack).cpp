#include <bits/stdc++.h>
using namespace std;

char strStack[1000001], tmpStack[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int idx1 = 0, idx2 = 0;
        cin >> str;
        for (auto e : str) {
            switch (e) {
                case '<':
                    if (idx1)
                        tmpStack[idx2++] = strStack[--idx1];
                    break;
                case '>':
                    if (idx2) 
                        strStack[idx1++] = tmpStack[--idx2];
                    break;
                case '-':
                    if (idx1)
                        idx1--;
                    break;
                default:
                    strStack[idx1++] = e;
			}
		}
        while (idx2) strStack[idx1++] = tmpStack[--idx2];
        strStack[idx1] = '\0';
        cout << strStack;
        cout << "\n";
    }
    return 0;
}