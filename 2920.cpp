#include <bits/stdc++.h>
using namespace std;

bool ascending, descending, mixed;

int main() {
    int arr[8];
    cin >> arr[0];
    for (int i = 1; i < 8; i++) {
        cin >> arr[i];
        if (arr[i-1] < arr[i])
            if (descending) { mixed = true; break; }
            else              ascending = true;
        else
            if (ascending) { mixed = true; break; }
            else             descending = true;
    }
    if (mixed)      cout << "mixed\n";
    else
        if (ascending)       cout << "ascending\n";
        else if (descending) cout << "descending\n";
    return 0;
}