#include <bits/stdc++.h>
#define PUSH '+'
#define POP  '-'
using namespace std;

int n, seqInt, current;
stack<int> seqStack;
vector<char> pushAndPop;

void pushStack () {
    while (current < seqInt) {
        pushAndPop.push_back(PUSH);
        seqStack.push(++current);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seqInt;
        pushStack();
        if (seqStack.top() == seqInt)  {
            pushAndPop.push_back(POP);
            seqStack.pop();
        }
        else if (current > seqInt) {
            cout << "NO";
            return 0;
        }
    }
    for (auto e : pushAndPop)
        cout << e << '\n';
	return 0;
}