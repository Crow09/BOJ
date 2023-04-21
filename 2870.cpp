#include <bits/stdc++.h>
using namespace std;

int idx;
vector<string> answer;

bool compare(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] < b[i]) return true;
			else if (a[i] > b[i]) return false;
		}
	}
	return true;
}

void numVector(string str) {
	int c_idx = idx;
	bool naNum = false;
	while ('0' <= str[idx] && str[idx] <= '9') {
		if (str[idx] == '0') {
			if (!naNum)
				c_idx++;
			else;
		}
		else
			naNum = true;
		idx++;
	}
//	cout << c_idx << ' ' << idx << endl;
//	cout << (str.substr(c_idx, idx-c_idx)) << endl;
	if (idx-c_idx > 0)
		answer.push_back(str.substr(c_idx, idx-c_idx));
	else if (c_idx-idx >= 0) answer.push_back("0");
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int len = str.length();
		for (idx = 0; idx < len; idx++) {
			
			if ('0' <= str[idx] && str[idx] <= '9')
				numVector(str);
			
		}
	}
	sort(answer.begin(), answer.end(), compare);
	for (auto e : answer)
		cout << e << endl;
	return 0;
}
/*
4
43 000002 000000000000000000000000000000000000000
0020
2
0000231233 0234 03596823948676890000453456737
*/
