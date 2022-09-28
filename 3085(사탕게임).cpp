#include<iostream>

using namespace std;

char map[50][50];
int N;
int ans = 1;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
bool visited[50][50][2];

bool is_in(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}

void cnt_candy(int r, int c, int init_dir) {

	int cnt = 1;
	int r1 = r + dr[init_dir], c1 = c + dc[init_dir];
	while (is_in(r1, c1) && map[r1][c1] == map[r][c]) {
		visited[r1][c1][init_dir] = true;
		cnt++;
		r1 = r1 + dr[init_dir], c1 = c1 + dc[init_dir];
	}

	r1 = r + dr[init_dir + 2], c1 = c + dc[init_dir + 2];
	while (is_in(r1, c1) && map[r1][c1] == map[r][c]) {
		visited[r1][c1][init_dir] = true;
		cnt++;
		r1 = r1 + dr[init_dir + 2], c1 = c1 + dc[init_dir + 2];
	}

	ans = max(ans, cnt);
}

void reset_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j][0] = false, visited[i][j][1] = false;
		}
	}
}

void solve() {
	
	reset_visited();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				if (!visited[i][j][k]) {
					cnt_candy(i, j, k);
				}
				//cnt_candy(i, j, k); 시간이 두배정도 차이나지만 가능하다. 중복해서 세는 경우를 따로 고려하지 않았다.
			}
		}
	}
}

void select_candy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N - 1 && j < N - 1) {//dir : 2,3
				int r2 = i + dr[2], c2 = j + dc[2];
				if (map[r2][c2] != map[i][j]) {
					swap(map[r2][c2], map[i][j]);
					solve();
					swap(map[r2][c2], map[i][j]);
				}
				r2 = i + dr[3], c2 = j + dc[3];
				if (map[r2][c2] != map[i][j]) {
					swap(map[r2][c2], map[i][j]);
					solve();
					swap(map[r2][c2], map[i][j]);
				}
			}
			else if (i < N - 1 && j == N - 1) {//dir : 3
				int r2 = i + dr[3], c2 = j + dc[3];
				if (map[r2][c2] != map[i][j]) {
					swap(map[r2][c2], map[i][j]);
					solve();
					swap(map[r2][c2], map[i][j]);
				}
			}
			else if (i == N - 1 && j < N - 1) {//dir : 2
				int r2 = i + dr[2], c2 = j + dc[2];
				if (map[r2][c2] != map[i][j]) {
					swap(map[r2][c2], map[i][j]);
					solve();
					swap(map[r2][c2], map[i][j]);
				}
			}
			else {
				//continue
			}
		}
	}
}


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
		}
	}

	select_candy();

	cout << ans << endl;
}