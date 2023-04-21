#include <bits/stdc++.h>
#define NOT_EMPTY !confront.empty()
#define FIRST confront.top().first
#define SECOND confront.top().second
using namespace std;

int N, height;
long long int cnt;
stack<pair<int,int>> confront;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height;
		int heightCnt = 1;
		while (NOT_EMPTY && height >= FIRST) {
			if (height == FIRST)
				heightCnt = SECOND+1;
			cnt += SECOND;
			confront.pop();
		}
		if (NOT_EMPTY) cnt++;
		confront.push({height, heightCnt});
	}
	cout << cnt << '\n';
    return 0;
}
