#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		unordered_map<string, int> map_clothes;
		for (int j = 0; j < n; j++) {
			string str, str1;
			cin >> str >> str1;	
			if (map_clothes[str1])
				map_clothes[str1]++;
			else
				map_clothes[str1] = 2;
		}
		unordered_map<string, int> ::iterator iter;
		int res = 1;
		for (iter = map_clothes.begin(); iter != map_clothes.end(); iter++)
			res*=(*iter).second++;
		cout << res-1 << endl;
	}
	return 0;
}
