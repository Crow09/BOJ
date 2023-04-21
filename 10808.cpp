#include <bits/stdc++.h>
using namespace std;

int main() {
	char str[101];
	int spl[28] = {};
	cin >> str;
	for (int i = 0; i < strlen(str); i++)
		spl[str[i]-'a']++;
	for (int i = 0; i < 26; i++)
		printf("%d ", spl[i]);
	return 0;
}
