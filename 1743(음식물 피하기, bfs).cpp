#include<iostream>

using namespace std;

int col, row;
int num;
int map[100][100];
int max_size = 0;
int food_size;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

bool is_in_and_is_exist(int i, int j) {
	return i < row && i >= 0 && j < col && j >= 0 && map[i][j] == 1;
}

void bfs(int i, int j) {
	map[i][j] = 2;
	food_size++;
	for (int k = 0; k < 4; k++) {
		if (is_in_and_is_exist(i + di[k], j + dj[k])) {
			bfs(i + di[k], j + dj[k]);
		}
	}
}

int main(void) {
	cin >> row >> col >> num;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = 0;//0:no 1:non_check 2:check
		}
	}

	for (int i = 0; i < num; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 1) {
				food_size = 0;
				bfs(i, j);
				if (max_size < food_size) {
					max_size = food_size;
				}
			}
		}
	}

	cout << max_size << endl;
}



