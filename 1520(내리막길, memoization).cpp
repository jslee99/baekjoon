#include<iostream>

using namespace std;

int map[500][500];
int dp[500][500];
int m, n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool is_in(int r, int c) {
	return r >= 0 && r < m&& c >= 0 && c < n;
}

int recur(int r, int c) {
	if (r == 0 && c == 0) {
		dp[0][0] = 1;
		return 1;
	}
	if (dp[r][c] > -1) {
		return dp[r][c];
	}

	int cnt = 0;
	int new_r, new_c;
	for (int i = 0; i < 4; i++) {
		new_r = r + dr[i], new_c = c + dc[i];
		if (is_in(new_r, new_c) && map[r][c] < map[new_r][new_c]) {
			cnt += recur(new_r, new_c);
		}
	}

	dp[r][c] = cnt;

	return cnt;
}



int main(void) {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}



	cout << recur(m-1, n-1) << endl;
}