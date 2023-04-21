#include <bits/stdc++.h>
using namespace std;

char wh[101][101];
int arr[101][101];

int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> wh[i][j];

	for (int i = 0; i < h; i++) {
		bool inCloud = false;
		for (int j = 0; j < w; j++) {
			if (wh[i][j] == 'c') {
				inCloud = true;
				arr[i][j] = 0;
			}
			else {
				if (inCloud)
					arr[i][j] = arr[i][j-1]+1;
				else
					arr[i][j] = -1;
			}
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%d ", arr[i][j]);
		cout << endl;
	}
	return 0;
}
