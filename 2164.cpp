#include <bits/stdc++.h>
using namespace std;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    queue<int> card;
    cin >> N;
    for (int i = 1; i <= N; i++)
        card.push(i);
    while (card.size() > 1) {
        card.pop();
        int tmp = card.front();
        card.pop();
        card.push(tmp);
    }
    cout << card.front() << '\n';
    return 0;
}