#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

unordered_map<int, int> ma;
vector<int> order;

bool compare(const pp& a, const pp& b) {
	return a.second > b.second;
}

int main() {
	int n, c, key, i;
	cin >> n >> c;
	for (i = 0; i < n; i++) {
		cin >> key;
		ma[key]++;
		if (find(order.begin(), order.end(), key) == order.end()) order.push_back(key);
	}
	
	vector<pp> sorted(ma.begin(), ma.end());
	vector<pp>:: iterator vecIter;
	
	sort(sorted.begin(), sorted.end(), compare);
	
	i = 0;
//	cout << sorted.size() << endl;
//	cout << order.size() << endl;
	
	while (!sorted.empty()) {
		int maxi = sorted[0].second;
		for (vecIter = sorted.begin(); vecIter != sorted.end(); vecIter++)
			if (maxi == (*vecIter).second && order[i] == (*vecIter).first) {
				while ((*vecIter).second--)
					cout << (*vecIter).first << ' ';
					
				sorted.erase(vecIter);
				order.erase(order.begin()+i);
				i = -1;
				n--;
				break;
			}
		i++;
		i%=n;
	}
	return 0;
}
