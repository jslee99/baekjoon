#include<iostream>

using namespace std;

int T;
int R = 16, C = 16;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int map[16][16];
bool visit[16][16];

bool isIn(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

void initVisit() {
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) visit[i][j] = false;
}

void dfs(int r, int c) {
	visit[r][c] = true;
	for (int k = 0; k < 4; k++) {
		int new_r = r + dr[k], new_c = c + dc[k];
		if (isIn(new_r, new_c) && !visit[new_r][new_c] && (map[new_r][new_c] == 0 || map[new_r][new_c] == 2 || map[new_r][new_c] == 3)) dfs(new_r, new_c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	T = 10;

	for (int t = 1; t <= T; t++) {
		cin >> t;
		initVisit();

		for (int i = 0; i < R; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < C; j++) {
				map[i][j] = str[j] - '0';
			}
		}

		int r, c;
		int rr, cc;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 2) {
					r = i, c = j;
				}
				if (map[i][j] == 3) {
					rr = i, cc = j;
				}
			}
		}

		dfs(r, c);

		if (visit[rr][cc]) {
			cout << '#' << t << ' ' << 1 << '\n';
		}
		else {
			cout << '#' << t << ' ' << 0 << '\n';
		}
	}
}