#include <bits/stdc++.h>
using namespace std;

int winner[2][2];
int allTime = 48*60, tmpTime = 48*60;

int main() {
	bool now1 = true, now2 = true;
	int n, mm, ss;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int team, minute, second;
		char colon;
		cin >> team >> minute >> colon >> second;
		minute *= 60;
		winner[team-1][0]++;
		if (team == 1) {
			if (winner[0][0] > winner[1][0]) {
				now2 = true;
				if (now1) {
					winner[0][1] += allTime-(minute+second);
					mm = minute;
					ss = second;
				}
				now1 = false;
			}
			else {
				if (winner[0][0] < winner[1][0]);
				else {winner[1][1] -= allTime-(minute+second); now2 = true;}
				now1 = true;
			}
		}
		else {
			if (winner[1][0] > winner[0][0]) {
				now1 = true;
				if (now2) {
					winner[1][1] += allTime-(minute+second);
					int mm = minute;
					int ss = second;
				}
				now2 = false;
			}
			else {
				if (winner[1][0] < winner[0][0]);
				else {winner[0][1] -= allTime-(minute+second); now1 = true;}
				now2 = true;
			}
		}
	}
	printf("%02d:%02d\n%02d:%02d", winner[0][1]/60, winner[0][1]%60, winner[1][1]/60, winner[1][1]%60);
	return 0;
}
/*
4
1 01:50
2 21:00
1 31:50
2 41:00

3
1 01:10
2 21:10
2 31:30

960
*/
