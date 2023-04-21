#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	
	string dir[50];
	string same;
	
	cin >> n;
	cin >> dir[0];
	same = dir[0];
	for (int i = 0; i < n-1; i++) {
		cin >> dir[i];
		for (int j = 0; dir[i][j] != '\0'; j++) {
			if (same[j] == dir[i][j]) 	same[j] = dir[i][j];
			else 						same[j] = '?';
		}
	}
	cout << same;
	return 0;
}
