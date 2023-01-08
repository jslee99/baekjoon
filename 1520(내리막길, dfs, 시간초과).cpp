#include<iostream>

using namespace std;

int map[500][500];
bool visited[500][500];
int cnt = 0;
int m, n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool is_in(int r, int c) {
	return r >= 0 && r < m&& c >= 0 && c < n;
}

void dfs(int r, int c) {
	if (r == m - 1 && c == n - 1) {
		cnt++;
		return;
	}

	visited[r][c] = true;
	int new_r, new_c;
	for (int i = 0; i < 4; i++) {
		new_r = r + dr[i], new_c = c + dc[i];
		if (is_in(new_r, new_c) && !visited[new_r][new_c] && map[r][c] > map[new_r][new_c]) {
			dfs(new_r, new_c);
		}
	}

	visited[r][c] = false;

	return;
}

int main(void) {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}

	dfs(0, 0);

	cout << cnt << endl;
}