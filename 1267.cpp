#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, call;
	unsigned long long int Y_sum = 0, M_sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> call;
		Y_sum += (call/30)+1;
		M_sum += (call/60)+1;
	}
	Y_sum *= 10;
	M_sum *= 15;
	if (Y_sum < M_sum)
		cout << "Y\n" << Y_sum;
	else if (Y_sum > M_sum)
		cout << "M\n" << M_sum;
	else
		cout << "Y M\n" << Y_sum;
	return 0;
}
