#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int map[100][100];
int N, M;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int cheese_num = 0;
int melting_num = 0;
pair<int, int> start;
bool visited[100][100];

void reset_visited() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;
}

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

void dfs2(int r, int c) {
	visited[r][c] = true;
	int new_r, new_c;
	for (int i = 0; i < 4; i++) {
		new_r = r + dr[i], new_c = c + dc[i];
		if (is_in(new_r, new_c)) {
			if (map[new_r][new_c] == 2 && !visited[new_r][new_c]) {
				dfs2(new_r, new_c);
			}
			else if (map[new_r][new_c] == 1) {
				if (is_melting(new_r, new_c)) {
					map[new_r][new_c] = 3;
				}
			}
		}
	}
}


int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheese_num++;
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

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (map[i][j] == 2) {
		start.first = i, start.second = j;
			break;
	}

	int _time = 0;

	do {
		reset_visited();
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] == 2) dfs2(i, j);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 3) {
					dfs1(i, j);
					melting_num++;
				}
			}
		}

		_time++;
	} while (cheese_num - melting_num);

	cout << _time << endl;
}
