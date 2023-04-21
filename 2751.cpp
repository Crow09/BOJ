#include <bits/stdc++.h>
#define MAX_SIZE 1000000
using namespace std;

int add_arr[MAX_SIZE];

void SortOfMerge(int arr[], int left, int mid, int right) {
	int l = left;
	int r = mid+1;
	int index = left;
	while (l <= mid && r <= right) {
		if (arr[l] <= arr[r])
			add_arr[index] = arr[l++];
		else
			add_arr[index] = arr[r++];
		index++;
	}
	if (l > mid)
		for (int i = r; i <= right; i++)
			add_arr[index++] = arr[i];
	else
		for (int i = l; i <= mid; i++)
			add_arr[index++] = arr[i];
	for (int i = left; i <= right; i++)
		arr[i] = add_arr[i];
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left+right)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		SortOfMerge(arr, left, mid, right);
	}
}

int main() {
	int n, *arr;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	mergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}
