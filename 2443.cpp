#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n-i; j < n; j++) cout << " ";
		for (int j = n*2; j > i*2+1; j--) cout << "*";
		cout << "\n";
	}
	return 0;
}
