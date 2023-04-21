#include <bits/stdc++.h>
using namespace std;

void pri(int i, int arr[]) {for (int j = 0; j < arr[i]/2; j++) printf("%c", i +'A');}

int main() {
	int al[27] = {}, cnt = 0;
	char str[51];
	cin >> str;
	for (int i = 0; i < strlen(str); i++)
		al[str[i]-'A']++;
	int tmp = -1;
	for (int i = 0; i < 26; i++) {
		if (al[i]%2) {cnt++; tmp = i;}
		if (cnt > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
	for (int s = 0; s < 2; s++) {
		if (!s)
			for (int i = 0; i < 26; i++) {
				pri(i, al);
			}
		else
			for (int i = 25; i >= 0; i--)
				pri(i, al);
		if (!s && tmp != -1)
			printf("%c", tmp+'A');
	}
	return 0;
}
