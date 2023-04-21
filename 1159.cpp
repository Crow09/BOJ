#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, firstLetter[28] = {};
	bool predaja = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char name[31];
		cin >> name;
		firstLetter[name[0]-'a']++;
	}
	for (int i = 0; i < 26; i++)
		if (firstLetter[i] >= 5) {printf("%c", i+'a'); predaja = false;}
	if (predaja) cout << "PREDAJA";
	return 0;
}
