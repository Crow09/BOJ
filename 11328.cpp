#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	char a[1001], b[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int charA[26] = {}, charB[26] = {};
		cin >> a >> b;
		int len = strlen(a);
		if (len != strlen(b)) {
			cout << "Impossible\n";
			continue;
		}
		for (int i = 0; i < len; i++) {
			charA[a[i]-'a']++;
			charB[b[i]-'a']++;
		}
		bool boool = true;
		for (int i = 0; i < 26; i++)
			if (charA[i] != charB[i]) {
				boool = false;
				break;
			}
		if (boool) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}

