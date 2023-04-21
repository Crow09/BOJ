#include <bits/stdc++.h>
using namespace std;

int arr[21], a, b;

void change(int s, int e) {
	if (s >= e) return;
	swap(arr[s], arr[e]);
	change(s+1, e-1);
}

int main() {
	for (int i = 1; i <= 20; i++)
		arr[i] = i;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		change(a, b);
	}
	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
	return 0;
}
