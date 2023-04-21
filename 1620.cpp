#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> map_number; //뒤에 붙은 이름은 key 값이다. 
unordered_map<string, int> map_poketMon;
vector<string> ans;

int main() {
	int n, m;
	char str[2001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		map_number.insert({i, str});
		map_poketMon.insert({str, i});
	}
	for (int i = 0; i < m; i++) {
		char str_input[2001];
		scanf("%s", str_input);
		if (isdigit(str_input[0])) {
			int int_input = stoi(str_input);
			auto res = map_number.find(int_input);
			cout << res->second << '\n';
		}
		else {
			auto res = map_poketMon.find(str_input);
			cout << res->second << '\n';
		}
	}
	return 0;
}
