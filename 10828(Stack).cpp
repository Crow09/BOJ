#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    stack<int> intStack;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int inputValue;
            cin >> inputValue;
            intStack.push(inputValue);
            continue;
        }
        else if (command == "pop") {
            if (intStack.empty())
                cout << -1;
            else {
                cout << intStack.top();
                intStack.pop();
            }
        }
        else if (command == "size")
            cout << intStack.size();
        else if (command == "empty")
            cout << intStack.empty();
        else {
            if (intStack.empty())
				cout << -1;
			else
                cout << intStack.top();
        }
        cout << '\n';
    }
    return 0;
}