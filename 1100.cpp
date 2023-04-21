#include <bits/stdc++.h>
using namespace std;

int main() {
	int res = 0;
	char chess[9][9];
	for (int i = 1; i <= 8; i++)
		cin >> chess[i];
	for (int i = 1; i <= 8; i++)
		for (int j = 0; j < 8; j++)
			if ((j+i)%2)
				if (chess[i][j] == 'F')
					res++;
	cout << res;
	return 0;
}
