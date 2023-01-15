#include<iostream>
#include<queue>

using namespace std;

int map[100][100];
int N, M;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool is_in(int r, int c) {
	return r < N&& r >= 0 && c < M&& c >= 0;
}

void dfs1(int r, int c) {
	map[r][c] = 2;
	int new_r, new_c;

	for (int i = 0; i < 4; i++) {
		new_r = r + dr[i], new_c = c + dc[i];
		if (is_in(new_r, new_c) && map[new_r][new_c] == 0) {
			dfs1(new_r, new_c);
		}
	}
}

bool is_melting(int r, int c) {
	int new_r, new_c;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		new_r = r + dr[i], new_c = c + dc[i];
		if (is_in(new_r, new_c) && map[new_r][new_c] == 2) {
			cnt++;
		}
	}
	if (cnt >= 2) return true;
	else return false;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int j = 0; j < M; j++) {
		if (map[0][j] == 0) {
			dfs1(0, j);
		}
		if (map[N - 1][j] == 0) {
			dfs1(N - 1, j);
		}
	}

	for (int i = 0; i < N; i++) {
		if (map[i][0] == 0) {
			dfs1(i, 0);
		}
		if (map[i][M - 1] == 0) {
			dfs1(i, M - 1);
		}
	}

	int _time = 0;
	int cnt;
	bool flag;
	do {
		cnt = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					cnt++;
					if (is_melting(i, j)) {
						q.push(make_pair(i, j));
					}
				}
			}
		}

		flag = cnt - q.size();

		while (!q.empty()) {
			pair<int, int> x = q.front();
			q.pop();

			map[x.first][x.second] = 0;
			dfs1(x.first, x.second);
		}


		_time++;
	} while (flag);

	cout << _time << endl;
}