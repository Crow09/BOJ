#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool isSame = false;
	string s, s1, s2;
	
	cin >> n >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 42) {s1 = s.substr(0, i); isSame = true;}
		else if (isSame) {s2 = s.substr(i, s.length()); break;}
	}
	cout << s1 << ' ' << s2 << endl;
	for (int i = 0; i < n; i++) {
		cin >> s;
		isSame = false;
		if (s.length() >= s1.length()+s2.length()) {
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] == s[i]) continue;
				else {isSame = true; break;}
			}
			if (!isSame)
				for (int i = s2.length(); i > 0; i--) {
					if (s[s.length()-i] == s2[s2.length()-i]) continue;
					else {isSame = true; break;}
				}
		}
		else isSame = true;
		if (isSame) cout << "NE" << endl;
		else cout << "DA" << endl;
	}
	return 0;
}
