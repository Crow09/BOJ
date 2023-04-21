#include <bits/stdc++.h>
using namespace std;

vector<string> s;

int stringSum(string a) {
	int len = a.length(), sum = 0;
	for (int i = 0; i < len; i++)
		if (a[i]-'0' >= 0  && a[i]-'0' <= 9)
			sum += a[i]-'0';
	return sum;
}

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else {
		int aSum = stringSum(a);
		int bSum = stringSum(b);
		if (aSum != bSum)
			return aSum < bSum;
	}
	return a < b;
}

int main() {
	int n;
	string S;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S;
		s.push_back(S);
	}
	sort(s.begin(), s.end(), compare);
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	return 0;
}
