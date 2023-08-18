#include<iostream>
#include<algorithm>

using namespace std;

int n;
int dice[10005][6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		dice[i][0] = a, dice[i][5]= f;
		dice[i][1] = b, dice[i][4] = d;
		dice[i][2] = c, dice[i][3] = e;
	}

	int ans = 0;
	for (int i = 0; i < 6; i++) {
		int res = 0;
		for (int j = 0; j < 6; j++) {
			if (i == j || 5 - i == j) continue;
			res = max(res, dice[0][j]);
		}
		int preNum = dice[0][5 - i];


		for (int j = 1; j < n; j++) {
			int idx;
			for (int k = 0; k < 6; k++) {
				if (preNum == dice[j][k]) {
					idx = k;
					break;
				}
			}
			preNum = dice[j][5 - idx];
			int x = 0;
			for (int k = 0; k < 6; k++) {
				if (k == idx || k == 5 - idx) continue;
				x = max(x, dice[j][k]);
			}
			res += x;
		}

		ans = max(ans, res);
	}

	cout << ans << '\n';
}