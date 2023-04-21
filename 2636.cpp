#include <bits/stdc++.h>
#define MAX 100
#define VISITED 1
#define DIR_TYPE 4
#define OUT_SIDE -1
#define AIR 0
#define CHEESE 1
#define MELT -2
using namespace std;

int h, w;
int cnt;
int piece[201];
int cheese[MAX][MAX];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void separationBFS() {
	bool vi[MAX][MAX];
	queue<pair<int,int>> plate; // first int is y, second int is x
	plate.push({0, 0});
	if (!cheese[0][0]) cheese[0][0] = OUT_SIDE;
	vi[0][0] = VISITED;
	while (!plate.empty()) {
		int y = plate.front().first;
		int x = plate.front().second;
		plate.pop();
		for (int dir = 0; dir < DIR_TYPE; dir++) {
			int ny = y+dy[dir];
			int nx = x+dx[dir];
			if (ny < 0 || ny >= h ||
				nx < 0 || nx >= w ||
				cheese[ny][nx] == CHEESE ||
				vi[ny][nx] == VISITED) continue;
			else {
				vi[ny][nx] = VISITED;
				cheese[ny][nx] = OUT_SIDE;
				plate.push({ny, nx});
			}
		}
	}
}

bool checkCheese() {
	bool check = false;
	bool vi[MAX][MAX];
	separationBFS();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			if (cheese[i][j] == CHEESE) {
				check = true;
				piece[cnt]++;
				for (int dir = 0; dir < DIR_TYPE; dir++) {
					int ny = i+dy[dir];
					int nx = j+dx[dir];
					if (cheese[ny][nx] <= OUT_SIDE &&
						!vi[ny][nx]) {
						cheese[i][j] = MELT;
						vi[i][j] = VISITED;
					}
				}
			}
	}
	return check;
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> cheese[i][j];
	while (1) {
		if (!checkCheese()) break;
		cnt++;
	}
	printf("%d\n%d", cnt, piece[cnt-1]);
	return 0;
}
