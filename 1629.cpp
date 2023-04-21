#include <bits/stdc++.h>
using namespace std;

long long int power(int n, int k, int c) {
	long long int tmp, res;
	if (k == 0) return 1;
	else if (k == 1) res = n;
	else {
		tmp = power(n, k/2, c);
		res = (tmp*tmp)%c;
		if (k%2) res = (res*n)%c;
	}
	return res%c;
} //n^k = (n^(k/2))^2
  //if k%2 = 1 -> result*n

int main() {
	int n, k, c;
	cin >> n >> k >> c;
	cout << power(n, k, c);
	return 0;
}
