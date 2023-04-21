#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, j, apple, now = 1, sum = 0;
	cin >> n >> m >> j;
	for (int i = 0; i < j; i++) {
		cin >> apple;
		if (now <= apple && now+(m-1) >= apple) continue;
		else if (apple < now) {
			sum += now-apple;
			now = apple;
		}
		else if (now+(m-1) < apple) {
			sum += apple-(now+m-1);
			now = apple-(m-1);
		}
//		printf("%d ", now);
	}
	cout << sum;
	return 0;
}
/*
10 9 10
10 1 10 10 10 10 10 10 10 2

5 1
3
1 5 3
*/
