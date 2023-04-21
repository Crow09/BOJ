#include <bits/stdc++.h>
using namespace std;

int N, idx, num;
vector<int> elementArr, res;
stack<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
		cin >> num;
		elementArr.push_back(num);
		res.push_back(-1);
	}
	idx = elementArr.size()-1;
	while (idx >= 0) {
		int element = elementArr[idx];
		while (!A.empty() && element >= A.top())
			A.pop();
		if (!A.empty())
			if (A.top() > element)
				res[idx] = A.top();
		A.push(element);
		idx--;
	}
	for (auto e : res)
		cout << e << ' ';
	cout << '\n';
    return 0;
}
