#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[100001];

vector<int> com[100001];
//vector<int> sorted;

void dfs(int start, int go, bool vi[]) {
	if (vi[go]) return;
	vi[go] = true;
	visited[start]++;
	for (int i = 0; i < com[go].size(); i++) {
		int y = com[go][i];
//		printf("%d %d\n", y, visited[y]);
		dfs(start, y, vi);
	}
}

int main() {
	int inMax = -1;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> b >> a;
		com[a].push_back(b);
		/*
			5 4
			3 1
			3 2
			4 3
			5 3
		*/
	}
//	cout << endl;
	for (int i = 1; i <= n; i++) {
		bool vi[100001] = {};
		dfs(i, i, vi);
	}
//	cout << endl;
	for (int i = 1; i <= n; i++) {
//		cout << visited[i] << ' ';
		inMax = max(inMax, visited[i]);
	}
//	cout << inMax;
	for (int i = 1; i <= n; i++)
		if (visited[i] == inMax)
			printf("%d ", i);
	return 0;
}

/*
2 2
1 2
2 1

5 4
3 1
3 2
4 3
5 3
*/
