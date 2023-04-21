#include <bits/stdc++.h>
#define MAX 20000
using namespace std;

string s[MAX];

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s+n, compare);
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] == s[i-1])
			continue;
		cout << s[i] << endl;
	}
}
