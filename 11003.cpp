#include <bits/stdc++.h>
#define NOT_EMPTY !findMin.empty()
#define FRONT findMin.front()
#define BACK findMin.back()
using namespace std;

int N, L, A;
deque<pair<int,int>> findMin;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> A;
		if (NOT_EMPTY && FRONT.first < i-L+1)
			findMin.pop_front();
		while (NOT_EMPTY && BACK.second >= A)
			findMin.pop_back();
        findMin.push_back({i, A});
        cout << FRONT.second << ' ';
	}
    cout << '\n';
    return 0;
}