#include<iostream>
#include<vector>

using namespace std;
int map[8][8];
int N, M;
vector<pair<int, int>> space;
int space_size;
int comb[4];//1 ~ 3
int map2[8][8];
bool visited[8][8];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans = 0;

bool can_enter(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M&& map2[r][c] != 1 && !visited[r][c];
}

void dfs_virus(int r, int c) {
	visited[r][c] = true;
	map2[r][c] = 2;

	for (int i = 0; i < 4; i++) {
		int new_r = r + dr[i], new_c = c + dc[i];
		if (can_enter(new_r, new_c)) dfs_virus(new_r, new_c);
	}
}

void reset_map2() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) map2[i][j] = map[i][j];
}

void reset_visited() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;
}

void solve() {
	reset_map2();
	for (int i = 1; i < 4; i++) map2[space[comb[i]].first][space[comb[i]].second] = 1;

	//virus
	reset_visited();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 2 && !visited[i][j]) dfs_virus(i, j);
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (map2[i][j] == 0) cnt++;
	ans = max(cnt, ans);
 }

void make_comb(int depth) {
	if (depth == 4) {
		solve();
		return;
	}

	for (int i = comb[depth - 1] + 1; i < space_size; i++) {
		comb[depth] = i;
		make_comb(depth + 1);
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (map[i][j] == 0) space.push_back(make_pair(i, j));

	space_size = (int)space.size();

	comb[0] = -1;
	make_comb(1);

	cout << ans << endl;
}