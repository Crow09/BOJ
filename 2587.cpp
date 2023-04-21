#include <bits/stdc++.h>
using namespace std;

int arr[5], avg, mid;

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		avg += arr[i];
	}
	sort(arr, arr+5);
	mid = arr[2];
	cout << avg/5 << "\n" << mid;
	return 0;
}
