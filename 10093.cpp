#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int mi, ma;
	cin >> mi >> ma;
	if (ma < mi) { long long int tmp = ma; ma = mi; mi = tmp; }
	if (ma == mi) cout << 0;
	else cout << ma-mi-1 << "\n";
	for (long long int i = mi+1; i < ma; i++) {
		cout << i << " ";
	}
	return 0;
}
