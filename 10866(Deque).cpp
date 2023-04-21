#include <bits/stdc++.h>
using namespace std;

int N, inputValue;
deque<int> intDeque;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		string command;
		cin >> command;
		if (command == "push_front") {
			cin >> inputValue;
			intDeque.push_front(inputValue);
			continue;
		}
		else if (command == "push_back") {
			cin >> inputValue;
			intDeque.push_back(inputValue);
			continue;
		}
		else if (command == "pop_front")
			if (intDeque.empty())
				cout << -1;
			else {
				cout << intDeque.front();
				intDeque.pop_front();
			}
		else if (command == "pop_back")
			if (intDeque.empty())
				cout << -1;
			else {
				cout << intDeque.back();
				intDeque.pop_back();
			}
		else if (command == "size")
			cout << intDeque.size();
		else if (command == "empty")
			cout << (int)intDeque.empty();
		else if (command == "front")
			if (intDeque.empty())
				cout << -1;
			else
				cout << intDeque.front();
		else
			if (intDeque.empty())
				cout << -1;
			else
				cout << intDeque.back();
		cout << '\n';
	}
	return 0;	
}
