#include <bits/stdc++.h>
#define MAX 51
#define PARENTLESS -1
#define VISITED 1
using namespace std;

vector<int> tree[MAX];

int N, tNode, delNode;
int root;
int leaf;
bool vi[MAX];

void DFS(int node) {
	if (vi[node] == VISITED) return;
	vi[node] = VISITED;
	if (tree[node].size() == 0 || 
	   (tree[node].size() == 1 &&
	    tree[node][0] == delNode)) leaf++;
	for (int i = 0; i < tree[node].size(); i++)
		if (tree[node][i] != delNode)
			DFS(tree[node][i]);
}
/*
-1(0) 0(1, 2) 1(3, 4)
2
-1(0) 0(2)
*/

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tNode;
		if (tNode == PARENTLESS) root = i;
		else tree[tNode].push_back(i);
	}
	cin >> delNode;
	if (delNode == root) {
		cout << 0;
		return 0;
	}
	DFS(root);
	cout << leaf;
	return 0;
}
