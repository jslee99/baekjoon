#include<iostream>

int N, M;
int map[300][300];
int delta[300][300];
bool visited[300][300];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
int _time = 0;
int ice = 1;

using namespace std;

void simulation() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++) if (map[i + dr[k]][j + dc[k]] == 0) cnt--;
			delta[i][j] = cnt;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (delta[i][j] == 0) continue;

			map[i][j] += delta[i][j];
			if (map[i][j] < 0) map[i][j] = 0;
			delta[i][j] = 0;
		}
	}
}

bool is_not_visited_ice(int r, int c) {
	return map[r][c] > 0 && !visited[r][c];
}

void dfs(int r, int c) {
	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		if (is_not_visited_ice(r + dr[i], c + dc[i])) dfs(r + dr[i], c + dc[i]);
	}
}

void counting_ice() {
	ice = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0 && !visited[i][j]) {
				dfs(i, j);
				ice++;
			}
		}
	}

	_time++;
	if (ice == 0) {
		ice = 2;
		_time = 0;
	}
}

void reset_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	while (ice < 2) {
		reset_visited();
		simulation();
		counting_ice();
	}

	cout << _time << endl;
}
