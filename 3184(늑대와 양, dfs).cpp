#include<iostream>

using namespace std;

char map[250][250];
int dc[4] = { -1, 0, 1, 0 };
int dr[4] = { 0, -1, 0, 1 };
int R, C;
int sheep = 0, wolf = 0;
int total_sheep = 0, total_wolf = 0;

bool is_not_fence_and_is_not_checked(char ch) {
	return ch != '1' && ch != '#';
}

bool is_in_and_is_not_fence_and_is_not_checked(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C && map[i][j] != '#' && map[i][j] != '1';
}

void dfs(int i, int j) {
	if (map[i][j] == 'v') {
		wolf++;
	}
	else if (map[i][j] == 'o') {
		sheep++;
	}
	map[i][j] = '1';

	for(int k = 0; k < 4; k++){
		int new_r = i + dr[k], new_c = j + dc[k];
		if (is_in_and_is_not_fence_and_is_not_checked(new_r, new_c)) {
			dfs(new_r, new_c);
		}
	}
}

int main(void){
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (is_not_fence_and_is_not_checked(map[i][j])) {
				dfs(i, j);
				if (!(sheep == 0 && wolf == 0)) {
					if (sheep > wolf) {
						total_sheep += sheep;
					}
					else {
						total_wolf += wolf;
					}
				}
				sheep = 0; wolf = 0;
			}				
		}
	}

	cout << total_sheep << ' ' << total_wolf << endl;
}