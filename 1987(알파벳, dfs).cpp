#include<iostream>

using namespace std;

char map[20][20];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int R, C;
int ans = -1;

bool is_in(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

void dfs(int r, int c, bool visited[][20], bool alphabet[], int cnt) {
	visited[r][c] = true;
	alphabet[map[r][c]] = true;
	ans = max(ans, cnt);

	int new_r, new_c;
	for (int k = 0; k < 4; k++) {
		new_r = r + dr[k], new_c = c + dc[k];
		if (is_in(new_r, new_c) && !visited[new_r][new_c] && !alphabet[map[new_r][new_c]]) {
			dfs(new_r, new_c, visited, alphabet, cnt + 1);
		}
	}

	visited[r][c] = false;
	alphabet[map[r][c]] = false;

}

int main() {
	bool visited[20][20];

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j] - 'A';
			visited[i][j] = false;
		}
	}

	bool alphabet[26];
	for (int i = 0; i < 26; i++) alphabet[i] = false;

	dfs(0, 0, visited, alphabet, 1);

	cout << ans << endl;
}