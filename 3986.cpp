#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> st;
		for (int j = 0; j < str.length(); j++) {
			if (st.empty()) st.push(str[j]);
			else if (st.top() == str[j]) st.pop();
			else st.push(str[j]);
		}
		if (st.empty()) cnt++;
		//BAAABBAAAB
	}
	cout << cnt;
	return 0;
}
