#include <bits/stdc++.h>
using namespace std;

bool josephus[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, repetition = 0, outPut = 0;
    cin >> N >> K;
    int idx = K;
    cout << "<";
    while (repetition < N) {
        idx = idx > N ? 1 : idx;
        if (!josephus[idx]) {
            if (outPut%K == 0) {
                cout << idx;
                josephus[idx] = true;
                repetition++;
                if (repetition < N) cout << ", ";
            }
            outPut++;
        }
        idx++;
    }
    cout << ">";
    return 0;
}
