#include <iostream>
using namespace std;
string ploca;
int a, b;
int dp[355][355];
int rek(int x, int y, int p1, int p2, char prev, int plr) {
	if (dp[x][y] != 0) {
		return dp[x][y] - 1;
	}
	if (prev == 'C') {
		if (plr == 1) {
			p2++;
		}
		else {
			p1++;
		}
	}
	if (p1 >= b || x == y) {
		dp[x][y] = 1;
		return 0;
	}
	if (p2 >= b) {
		dp[x][y] = 2;
		return 1;
	}
	if (rek(x + 1, y, p1, p2, ploca[x], (plr + 1) % 2) == plr) {
		dp[x][y] = plr;
		return plr;
	}
	if (rek(x, y - 1, p1, p2, ploca[y], (plr + 1) % 2) == plr) {
		dp[x][y] = plr;
		return plr;
	}
	dp[x][y] = (plr + 1) % 2 + 1;
	return (plr + 1) % 2;
}

int main(void) {
	cin >> a >> b;
	cin >> ploca;
	int state = rek(0, a - 1, 0, 0, 'P', 1);
	if (state) {
		cout << "DA";
	}
	else {
		cout << "NE";
	}
	return 0;
}
