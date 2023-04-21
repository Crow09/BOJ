#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, cnt = 0;
	cin >> n;
	for (i = 666; cnt < n; i++) {
		string str = to_string(i);
		if (str.find("666") != string::npos) cnt++;
	}
	cout << i-1;
	return 0;
}
