#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int arr[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j-1] > arr[j]) {
			swap(arr[j], arr[j-1]);
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
