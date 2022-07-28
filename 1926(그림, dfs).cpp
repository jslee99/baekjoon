#include<iostream>
#include<cmath>

using namespace std;
int map[500][500];
int n, m;
int _count = 0;
int cur = 0;
int _max = 0;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool is_in_and_is_not_visited(int i, int j) {
	return i >= 0 && i < n&& j >= 0 && j < m && map[i][j] == 1;
}

void dfs(int i, int j) {
	map[i][j] = -1;
	cur++;
	for (int k = 0; k < 4; k++) {
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (is_in_and_is_not_visited(new_i, new_j)) {
			dfs(new_i, new_j);
		}
	}
}

int main(void){
	cin >> n >> m;//row, column
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				_count++;
				_max = max(cur, _max);
				cur = 0;
			}
		}
	}
	cout << _count << endl << _max << endl;
}