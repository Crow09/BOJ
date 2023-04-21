#include <bits/stdc++.h>
using namespace std;

int vowel, consonant, continuousEO;
char v[5] = {'a', 'e', 'i', 'o', 'u'};
bool isVowel, good;

bool findThat(string str) {
	for (int i = 0; i < 5; i++)
		if (str.find(v[i]) != string::npos) return true;
	return false;
}

bool found(char al) {
	for (int i = 0; i < 5; i++)
		if (al == v[i]) return true;
	return false;
}

int main() {
	while (1) {
		string str;
		scanf("%s", &str);
		if (str == "end") break;
		int len = str.length();
		vowel = 0; consonant = 0; continuousEO = 0; good = false;
		isVowel = findThat(str);
		if (isVowel) {
			good = true;
			for (int i = 0; i < len; i++) {
				if (found(str[i])) {
					if (consonant) {consonant = 0; vowel = 1;}
					else vowel++;
				}
				else {
					if (vowel) {consonant = 1; vowel = 0;}
					else consonant++;
				}
				if (str[i-1] == str[i]) {
					if (str[i] == 'e' ||
						str[i] == 'o') continuousEO++;
					else {good = false; break;}
				}
				if (continuousEO > 1 || vowel > 2 || consonant > 2) {good = false; break;}
			}
		}
		if (good) 	printf("<%s> is acceptable.\n", str.c_str());
		else		printf("<%s> is not acceptable.\n", str.c_str());
	}
	return 0;
}
