#include <bits/stdc++.h>
using namespace std;

string graph[10] = {"black", "brown", "red", "orange", "yellow",
					"green", "blue", "violet", "grey", "white"};

int main() {
	long long int res = 0;
	string ohm1, ohm2, ohm3;
	cin >> ohm1 >> ohm2 >> ohm3;
	for (int i = 0; i < 10; i++) {
		if (ohm1 == graph[i]) res += i*10;
		if (ohm2 == graph[i]) res += i;
	}
	for (int i = 0; i < 10; i++)
		if (ohm3 == graph[i]) res *= pow(10, i);
	cout << res;
	return 0;
}
