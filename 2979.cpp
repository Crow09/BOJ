#include <bits/stdc++.h>
using namespace std;

int parkingLot[101];

int main() {
	int a, b, c, sum = 0;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int i = s; i < e; i++) {
			if (parkingLot[i] == 0)
				parkingLot[i] = a;
			else if (parkingLot[i] == a)
				parkingLot[i] = b*2;
			else if (parkingLot[i] == b*2)
				parkingLot[i] = c*3;
		}
	}
	for (int i = 0; i <= 100; i++)
		sum += parkingLot[i];
	cout << sum;
	return 0;
}
