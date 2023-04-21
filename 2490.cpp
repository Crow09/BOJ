#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int n = 0;
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			n += tmp;
		}
		switch (n) {
			case 4:
				cout << "E" << "\n";
				break;
			case 3:
				cout << "A" << "\n";
				break;
			case 2:
				cout << "B" << "\n;
				break;
			case 1:
				cout << "C" << "\n;
				break;
			default:
				cout << "D" << "\n;
				break;
		}
	}
	return 0;
}
