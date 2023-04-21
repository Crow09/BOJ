#include <bits/stdc++.h>
using namespace std;

list<char> str;
list<char>:: iterator iter;
char cStr[600001];

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, len;
	cin >> cStr;
	len = strlen(cStr);
	for (int i = 0; i < len; i++)
		str.push_back(cStr[i]);
	cin >> n;
	iter = str.end();
	for (int i = 0; i < n; i++) {
		char oper, insertChar;
		cin >> oper;
		if (oper == 'L' && iter != str.begin()) iter--;
		else if (oper == 'D' && iter != str.end()) iter++;
		else if (oper == 'P') {
			cin >> insertChar;
			str.insert(iter, insertChar);
		}
		else if (oper == 'B' && str.size() > 0 && iter != str.begin()) {
			iter--;
			iter = str.erase(iter);
		}
	}
	for (iter = str.begin(); iter != str.end(); iter++)
		cout << *iter;
	cout << "\n";
	return 0;
}
