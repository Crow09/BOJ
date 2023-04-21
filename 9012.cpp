#include <bits/stdc++.h>
using namespace std;

int T, vps;
string PS, ans[2] = {"NO\n", "YES\n"};

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		stack<char> conc;
		vps = 1;
		cin >> PS;
		for (auto e : PS) {
			if (e == '(') conc.push(e);
			else {
				if (conc.empty()) { vps = 0; break; }
				else conc.pop();
			}
		}
		if (!conc.empty())
			vps = 0;
		cout << ans[vps];
	}
	return 0;
}