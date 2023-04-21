#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> intQueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int inputValue;
            cin >> inputValue;
            intQueue.push(inputValue);
            continue;
        }
        else if (command == "pop") {
            if (intQueue.empty()) cout << -1;
            else {
                cout << intQueue.front();
                intQueue.pop();
            }
        }
        else if (command == "size") cout << intQueue.size();
        else if (command == "empty") cout << (int)intQueue.empty();
        else if (command == "front") {
            if (intQueue.empty()) cout << -1;
            else cout << intQueue.front();
        }
        else {
            if (intQueue.empty()) cout << -1;
            else cout << intQueue.back();
        }
        cout << '\n';
    }
    return 0;
}