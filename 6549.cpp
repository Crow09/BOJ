#include <bits/stdc++.h>
#define NOT_EMPTY !histogram.empty()
#define TOP histogram.top()
#define POP histogram.pop()
#define PUSH histogram.push
#define SIZE (i - TOP - 1)
#define LLD long long int
using namespace std;

int n = 1, h;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(n) {
        cin >> n;
        long long int res = 0;
        vector<long long int> height(n + 2);
        stack<int> histogram;
        PUSH(0);
        for (int i = 1; i <= n + 1; i++) {
            if (i <= n)
                cin >> height[i];
            while (NOT_EMPTY && height[i] < height[TOP]) {
                int tmp = TOP;
                POP;
                if (res < height[tmp] * SIZE)
                    res = height[tmp] * SIZE;
            }
            PUSH(i);
        }
        if (n)
            cout << res << '\n';
    }
    return 0;
}