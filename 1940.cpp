#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, material[15001] = {}, sum = 0, cnt = 0, tmp;
	bool isNot = true;
	cin >> n >> m;
	if (m > 200000) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> material[i];

	sort(material, material+n);
	int l = 0, r = n-1;
	while (l < r) {
		if (material[l]+material[r] == m) {
			cnt++;
			l++;
			r--;
		}
		else if (material[l]+material[r] < m)
			l++;
		else
			r--;
	}
	cout << cnt;
	return 0;
}
