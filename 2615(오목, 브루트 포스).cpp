#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<stack>
#include<set>
#include<map>

using namespace std;

int a[20][20];
int dr[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
int dc[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

bool isIn(int r, int c) {
	return r > 0 && r < 20 && c > 0 && c < 20;
}

bool check(int r, int c, int x, int d) {
	for (int i = 0; i < 4; i++) {
		int rr = r;
		int cc = c;
		int cnt = 0;
		while (isIn(rr, cc) && a[rr][cc] == x) {
			cnt++;
			rr = rr + dr[i];
			cc = cc + dc[i];
		}

		int j = (i + 4) % 8;
		rr = r + dr[j];
		cc = c + dc[j];
		while (isIn(rr,cc) && a[rr][cc] == x) {
			cnt++;
			rr = rr + dr[j];
			cc = cc + dc[j];
		}

		if (cnt == 5)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 20; i++) for (int j = 1; j < 20; j++) cin >> a[i][j];

	for (int j = 1; j < 20; j++) {
		for (int i = 1; i < 20; i++) {
			if (a[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					if (check(i, j,1, k)) {
						cout << 1 << '\n';
						cout << i << ' ' << j << '\n';
						return 0;
					}
				}
			}
			else if (a[i][j] == 2) {
				for (int k = 0; k < 4; k++) {
					if (check(i, j, 2, k)) {
						cout << 2 << '\n';
						cout << i << ' ' << j << '\n';
						return 0;
					}
				}
			}
		}
	}

	cout << 0 << '\n';
}