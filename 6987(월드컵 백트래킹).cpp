#include<iostream>

using namespace std;

int a[6][3];

int r[4][6][3];
int ans[4];

void calc() {
	for (int i = 0; i < 4; i++) {
		if (ans[i] == 1) continue;

		bool flag = true;
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				if (a[j][k] != r[i][j][k]) flag = false;
			}
		}
		if (flag) ans[i] = 1;
	}
}

void f(int x, int y) {
	if (x == 5 && y == 6) {
		calc();
		return;
	}

	//x < y
	int xx = x, yy = (y + 1) % 6;
	if (yy == 0) xx++;

	if (xx >= yy) {
		yy = xx + 1;
	}



	//win
	a[x][0]++, a[y][2]++;
	f(xx, yy);
	a[x][0]--, a[y][2]--;
	//draw
	a[x][1]++, a[y][1]++;
	f(xx, yy);
	a[x][1]--, a[y][1]--;
	//lose
	a[x][2]++, a[y][0]++;
	f(xx, yy);
	a[x][2]--, a[y][0]--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> r[i][j][k];
			}
		}
	}

	f(0, 1);

	for (int i = 0; i < 4; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}