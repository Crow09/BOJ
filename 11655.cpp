#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	getline(cin, S);
	for (int i = 0; i < S.length(); i++) {
		if (S[i] > '9') {
			if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
				S[i]-=13;
			if ((S[i] >= 'A'-13 && S[i] < 'A') ||
				(S[i] >= 'a'-13 && S[i] < 'a')) S[i]+=25+1;
		}
	}
	for (int i = 0; i < S.length(); i++)
		cout << S[i];
	return 0;
}