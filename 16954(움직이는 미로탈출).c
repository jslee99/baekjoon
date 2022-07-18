#include<stdio.h>

int block[9][8];//on j column at which row block is included in 0 seconds
int dx[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0 };
int dy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0 };

int solve(int x, int y, int time) {
	if (x == 0 && y == 7) {
		return 1;
	}

	int idx = 0;
 	while (block[idx][y] != -1) {
		if (block[idx][y] + time == x)
			return 0;
		idx++;
	}
	for (int i = 0; i < 9; i++) {
		int new_x = x + dx[i], new_y = y + dy[i];
		if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
			int idx = 0;
			int sign = 0;
			while (block[idx][new_y] != -1) {
				if (block[idx][new_y] + time == new_x) {
					sign = 1;
					break;
				}
				idx++;
			}
			if (sign == 1)
				continue;
			int res = solve(new_x, new_y, time + 1);
			if (res == 1)
				return 1;
		}
	}
	return 0;
}

int main(void) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 8; j++)
			block[i][j] = -1;

	for (int i = 0; i < 8; i++) {
		char buf[9];
		scanf("%s", &buf);
		for (int j = 0; j < 8; j++) {
			if (buf[j] == '#') {
				int idx = 0;
				while (block[idx][j] != -1)
					idx++;
				block[idx][j] = i;
			}
		}
	}
	int res = solve(7, 0, 0);
	printf("%d\n", res);
	//printf("%d\n", solve(7, 0, 0));

}


