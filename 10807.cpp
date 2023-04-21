#include <bits/stdc++.h>
using namespace std;

int n, v, cnt, arr[101];

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> v;
	for (int i = 0; i < n; i++)
		if (arr[i] == v)
			cnt++;
	cout << cnt;
	return 0;
}
