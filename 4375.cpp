#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int ans = 1, len = 1;
		while (ans%n) {
			ans = (ans*10+1)%n;
			len++;
		}
		cout << len << endl;
	}
	return 0;
}
