#include <bits/stdc++.h>
using namespace std;

string openBracket = "({[";
string closeBracket = ")}]";

int main() {
	while (1) {
		string str;
		getline(cin, str);
		if (str == ".") break;
		stack<char> br;
		for (auto e : str) {
			if (openBracket.find(e) != string:: npos) br.push(e);
			else if (closeBracket.find(e) != string:: npos) {
				if (br.empty()) {br.push(e); break;}
				else if ((br.top() == '(' && e == ')') ||
						(br.top() == '{' && e == '}') ||
						(br.top() == '[' && e == ']')) br.pop();
				else break;
			}
		}
		if (br.empty())  printf("yes\n");
		else 			 printf("no\n");
	}
	return 0;
}
