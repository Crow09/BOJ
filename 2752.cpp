#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[3], index;
	cin >> arr[0] >> arr[1] >> arr[2];
	for (int i = 0; i < 3; i++) {
		int min = 0x7fffffff;
		for (int j = i; j < 3; j++)
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		swap(arr[i], arr[index]);
	}
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
	return 0;
}
