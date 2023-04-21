#include <bits/stdc++.h>
using namespace std;

int number[10], ma;

int main() {
	int n;
	cin >> n;
	while (n) {
		if (n%10 == 9 || n%10 == 6) {
			if (number[9] < number[6]) number[9]++;
			else number[6]++;
		}
		else number[n%10]++;
		n /= 10;
	}
	for (int i = 0; i <= 9; i++)
		if (ma < number[i]) ma = number[i];
	cout << ma;
	return 0;
}
