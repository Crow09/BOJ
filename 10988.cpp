#include <bits/stdc++.h>
using namespace std;

bool palindrome(char word[]) {
	for (int i = 0; i < strlen(word); i++) 
		if (word[i] != word[strlen(word)-i-1]) return false;
	return true;
}

int main() {
	char word[101];
	cin >> word;
	cout << palindrome(word);
	return 0;
}
